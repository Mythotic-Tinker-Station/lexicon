__wad = {}
__wad.list = {}
__wad.debug = false
-- bytes to int
function __wad:bti(str,endian,signed)
    local t={str:byte(1,-1)}
    if endian=="big" then
        local tt={}
        for k=1,#t do
            tt[#t-k+1]=t[k]
        end
        t=tt
    end
    local n=0
    for k=1,#t do
        n=n+t[k]*2^((k-1)*8)
    end
    if signed then
        n = (n > 2^(#t-1) -1) and (n - 2^#t) or n
    end
    return n
end

function __wad:removePadding(str)
	local newstr = ""
	for i = 1, #str do
		if str:sub(i,i) == "\0" then break end
		newstr = newstr .. str:sub(i,i)
	end
	return newstr
end

function __wad:debugEx(text)
	if self.debug == true then
		print(text)
	end
end



function __wad:load(path)

	self:debugEx("LOAD....: '" .. path .. "'")
	
	-- opening
	self:debugEx("OPEN '" .. path .. "'")
	local f = io.open(path, "rb")
	if f == nil then error("Failed to open '" .. path .. "'", 2) end
	
	-- header
	local wadtype = f:read(4)
	local lumpamount = self:bti(f:read(4))
	local dirpointer = self:bti(f:read(4))
	
	self:debugEx("HEAD....: '" .. tostring(wadtype) .. "' '" .. tostring(lumpamount) .. "' '" .. tostring(dirpointer) .. "'")
	
	if wadtype ~= "PWAD" and wadtype ~= "IWAD" then error("Incorrect WAD Header: WAD type is not a PWAD or IWAD", 2) end
	if type(lumpamount) ~= "number" then 			error("Incorrect WAD Header: File amount is not a number", 2) end
	if type(dirpointer) ~= "number" then 			error("Incorrect WAD Header: Directory location is not a number", 2) end
	
	-- move to directory position
	local filepos = dirpointer
	f:seek("set", dirpointer)
	self:debugEx("Moved to dir position")
	
	-- some setup
	local data = {}															
	data.path = path
	
	-- each lump
	for i = 1, lumpamount do											
		local pos = self:bti(f:read(4))									
		local size = self:bti(f:read(4))								
		local name = self:removePadding(f:read(8))					
		
		if name == nil then error("Lump Error: Lump has no name", 2) end
		if size == nil then error("Lump Error: '" .. name .. "' size is nil", 2) end
		if pos == nil then 	error("Lump Error: '" .. name .. "' location is nil", 2) end
		
		filepos = filepos + 16
		data[i] = {}
		
		if size ~= 0 then												
			f:seek("set", pos)	
			data[i].name = name
			data[i].data = f:read(size)
            data[i].size = size
            data[i].format = "file"
			f:seek("set", filepos)
		else
			data[i].name = name
			data[i].data = ""
            data[i].size = 0
            data[i].format = "marker"
		end
        
		self:debugEx("Loaded " .. path .. ":" .. name .. ":" .. size .. ":" .. pos)
	end

     -- for each lump

    local mapcount = 0
    local doomcount = 0
    local hexencount = 0
    local udmfcount = 0
    
    local l = 1
    while(l <= lumpamount) do

        -- check for doom/hexen maps
        local i = 1
        if data[l].name == "THINGS" then
            local label = l-1

            if data[label + i].name ~= "THINGS"    then goto continue  else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "LINEDEFS"  then goto continue  else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "SIDEDEFS"  then goto continue  else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "VERTEXES"  then goto continue  else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "SEGS"      then                else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "SSECTORS"  then                else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "NODES"     then                else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "SECTORS"   then goto continue  else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "REJECT"    then                else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            if data[label + i].name ~= "BLOCKMAP"  then                else i = i + 1 end
            if label + i >= lumpamount then goto mapdone end
            
            ::mapdone::
            if data[label + i].name == "BEHAVIOR"  then
                i = i + 1
                data[label].format = "MapHexen"
                hexencount = hexencount + 1
                if label + i >= lumpamount then goto mapdone2 end
                if data[label + i].name ~= "SCRIPTS"  then             else i = i + 1 end
            else
                data[label].format = "MapDoom"
                doomcount = doomcount + 1
            end
            
            ::mapdone2::
            mapcount = mapcount + 1
            data[label].size = i
        end
        
        ::continue::
        -- check for udmf format
        if data[l].name == "TEXTMAP" then
            for ml = l, lumpamount do
                if data[ml].name == "ENDMAP" then
                    udmfcount = udmfcount + 1
                    mapcount = mapcount + 1
                    data[l-1].format = "MapUDMF"
                    data[l-1].size = 0
                    goto next
                end
            end
        end
        ::next::
        l = l + i
    end

	f:close()	
	self:debugEx("Closed WAD '" .. path .. "'")
	return data
end

function __wad:save(path)

end

return __wad

