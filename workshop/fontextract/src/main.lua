


local page =
{

}

function page:init()

	self.fontname 		= "FontB"

    self.sheet = {}
	self.sheet.name 	= "page2.png"												-- sheet filename
	self.sheet.data 	= self:loadImageData()										-- sheet image data
	self.sheet.image 	= love.graphics.newImage(self.sheet.data)					-- sheet image object
	self.sheet.width 	= self.sheet.data:getWidth()								-- sheet image x res
	self.sheet.height 	= self.sheet.data:getHeight()								-- sheet image y res

	self.chars 			= {}
	self.chars.width 	= 18
	self.chars.height 	= 32
	self.chars.chars  	= {} -- my naming schemes are unmatched

	if self.sheet.width % self.chars.width ~= 0 then error("Sheet width is not a multiple of slice width") end
	if self.sheet.height % self.chars.height ~= 0 then error("Sheet height is not a multiple of slice height") end

	self.sheet.xcount 	= self.sheet.width / self.chars.width						-- number of chars on the x axis within the sheet
	self.sheet.ycount 	= self.sheet.height / self.chars.height						-- number of chars on the y axis within the sheet
	self.sheet.total 	= self.sheet.xcount*self.sheet.ycount

	self:gatherChars()
	self:extractChars()
end

function page:loadImageData()
    local f, err = io.open(self.sheet.name, "rb")
    if f then
        local data = f:read("*all")
        f:close()
        if data then
            data = love.filesystem.newFileData(data, "")
            return love.image.newImageData(data)
        end
	else
		error(err)
    end
end

function page:gatherChars()

	local depth = 0
	for h = 0, self.sheet.height-1, self.chars.height do
		for w = 0, self.sheet.width-1, self.chars.width do

			local i = #self.chars.chars+1
			self.chars.chars[i] = love.image.newImageData(self.chars.width, self.chars.height)

			for x = 0, self.chars.width-1 do
				for y = 0, self.chars.height-1 do
					local r, g, b, a = self.sheet.data:getPixel(x+w, y+h)
					self.chars.chars[i]:setPixel(x, y, r, g, b, a)
				end
			end
		end
	end
end

function page:extractChars()
	for i = 1, #self.chars.chars do
		local f, err = io.open(string.format("output/%s%03d.png", self.fontname, i-1), "wb")
		if f then
			f:write(self.chars.chars[i]:encode("png"):getString())
			f:flush()
			f:close()
		else
			error(err)
		end
	end
end


function love.load()
	page:init()
end












