
function love.load(arg)
    
    class = require("m_30log")
    streamwriter = require("cls_streamwriter")
    wadreader = require("wad")

    
    -- inti filesystem stuff
    require("lovefs")
    fs = lovefs()
    local path_maps = love.filesystem.getSource() .. "/../../../pk3/maps"
    fs:cd(path_maps)
    
    -- get all wad files
    local wads = {}
    local w = 1
    for i, v in ipairs(fs.files) do
        if v:sub(-4) == ".wad" or v:sub(-4) == ".WAD" then
            local index = #wads+1
            wads[index] = { path_full = path_maps .. "/" .. v, name = v, path = path_maps .. "/" }
        end
    end

    while w <= #wads do

        -- for each lump
        local lumps = wadreader:load(wads[w].path_full)
       
        if wads[w].name ~= "VR.wad" and wads[w].name ~= "TITLEMAP.wad" then
       
            print(string.format("[%d/%d] Cleaning: %s...", w, #wads, wads[w].name))
            
            for l = 1, #lumps do
                
                if lumps[l].name == "TEXTMAP" then
                    
                    -- look for and remove all comments
                    local found_comment = 0
                    
                    local c = 0
                    local size = #lumps[l].data
                    
                    lumps[l].data = string.gsub(lumps[l].data, "//.-\n", "")
                    lumps[l].data = string.gsub(lumps[l].data, " ", "")
                    lumps[l].data = string.gsub(lumps[l].data, "%.000", "")
                    lumps[l].data = string.gsub(lumps[l].data, "%.0", "")
                    lumps[l].data = string.gsub(lumps[l].data, "id=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "id=%-1;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "height=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "angle=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "special=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "arg0=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "arg1=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "arg2=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "arg3=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "arg4=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "heightfloor=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "heightceiling=0;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "lightlevel=160;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "sideback=%-1;", "")
                    lumps[l].data = string.gsub(lumps[l].data, "texturetop=\"%-\";", "")
                    lumps[l].data = string.gsub(lumps[l].data, "texturemiddle=\"%-\";", "")
                    lumps[l].data = string.gsub(lumps[l].data, "texturebottom=\"%-\";", "")
                    lumps[l].data = string.gsub(lumps[l].data, "\n", "")
                    
                    
                    lumps[l].size = #lumps[l].data
                end
            end
            
            
            
            
            local data = streamwriter(wads[w].path_full)
            
            -- header
            data:writeString("PWAD")
            data:write32(#lumps)
            data:write32(0)
            local filedatepos = data.file:seek()
            
            for l = 1, #lumps do
                if lumps[l].size > 0 then
                    data:writeString(lumps[l].data)
                    lumps[l].offset = filedatepos
                    filedatepos = data.file:seek()
                else
                    data:writeString(lumps[l].data)
                    lumps[l].offset = 0
                end
            end
            
            -- directory
            for l = 1, #lumps do
                data:write32(lumps[l].offset)
                data:write32(lumps[l].size)
                data:writeStringPad(lumps[l].name, 8)
            end

            local dirpos = (data.file:seek()-(#lumps * 16))
            data.file:seek("set", 8)
            data:write32(dirpos)

            data:close()
        end
        
        w = w + 1
    end

end

function love.update(dt)
    
end

function love.draw()

end


















