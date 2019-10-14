
--[[
    Stream writeer Object - by Tribeam
    Note on endianness: false for little, true for big
]]

local streamwriter = class {}

function streamwriter:init(path)
    self.file = io.open(path, "wb")

end

-- write a single byte
function streamwriter:write8(num, signed)
	if num == nil then error("write8(" .. num .. ", " .. signed .. "): arg1 is nil.", 2) end
	if signed then num = bit.xor((num-1), 0xFF) end

    self.file:write(string.char(num))
end

-- write a single word
function streamwriter:write16(num, signed, endian)
	if num == nil then error("write16(" .. num .. ", " .. signed .. "): arg1 is nil.", 2) end
	if signed then num = bit.xor((num-1), 0xFFFF) end
	if endian == "big" then
		self:write8(bit.band(bit.rshift(num, 8), 0xFF))
		self:write8(bit.band(num, 0xFF))
	else
        self:write8(bit.band(num, 0xFF))
		self:write8(bit.band(bit.rshift(num, 8), 0xFF))
	end
end

-- write a single long
function streamwriter:write32(num, signed, endian)
    if signed then num = bit.bxor((num-1), 0xFFFFFFFF) end
    if endian == "big" then
        self:write8(bit.band(bit.rshift(num,24), 0xFF))
        self:write8(bit.band(bit.rshift(num,16), 0xFF))
        self:write8(bit.band(bit.rshift(num,8), 0xFF))
        self:write8(bit.band(num, 0xFF))
    else

        self:write8(bit.band(num, 0xFF))
        self:write8(bit.band(bit.rshift(num,8), 0xFF))
        self:write8(bit.band(bit.rshift(num,16), 0xFF))
        self:write8(bit.band(bit.rshift(num,24), 0xFF))
    end
end

-- write a string of n length
function streamwriter:writeString(str)
    self.file:write(str)
end

-- write a string of n length
function streamwriter:writeStringPad(str, pad)

    self.file:write(str)
    for i = 1, pad - #str do
        self.file:write("\0")
    end
    
end

-- skip a byte
function streamwriter:skip8()
    self.pos = self.pos+1
end

-- skip a word
function streamwriter:skip16()
    self.pos = self.pos+2
end

-- skip a long
function streamwriter:skip32()
    self.pos = self.pos+4
end

-- skip N number of bytes
function streamwriter:skipN(n)
    self.pos = self.pos+n
end

-- return current position
function streamwriter:getpos()
    return self.pos
end

-- set current position
function streamwriter:setpos(n)
    self.pos = n
end

-- get if we are at the end of string
function streamwriter:eos()
    if self.pos >= #self.str then return true else return false end
end

-- get if we are at the end of string
function streamwriter:close()
    self.file:close()
end

return streamwriter