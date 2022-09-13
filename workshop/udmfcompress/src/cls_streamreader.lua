
--[[
    Stream Reader Object - by Tribeam
    Note on endianness: false for little, true for big
]]

local streamreader = class {}

function streamreader:init(str)
    self.str = str
    self.pos = 1
end

-- read a single byte
function streamreader:read8()
    local startpos = self.pos
    self.pos = self.pos+1
    return string.byte(self.str:sub(startpos, startpos))
end

-- read a single word
function streamreader:read16(endian)
    local b1, b2
    if not endian then
        b1 = self:read8()
        b2 = bit.lshift(self:read8(), 8)
    else
        b1 = bit.lshift(self:read8(), 8)
        b2 = self:read8()
    end
    return bit.bor(b1, b2)
end

-- read a single long
function streamreader:read32(endian)
    local b1, b2, b3, b4
    if not endian then
        b1 = self:read8()
        b2 = bit.lshift(self:read8(), 8)
        b3 = bit.lshift(self:read8(), 16)
        b4 = bit.lshift(self:read8(), 24)
    else
        b1 = bit.lshift(self:read8(), 24)
        b2 = bit.lshift(self:read8(), 16)
        b3 = bit.lshift(self:read8(), 8)
        b4 = self:read8()
    end
    return bit.bor(b1, b2, b3, b4)
end

-- read a string of n length
function streamreader:readString(n)
    local startpos = self.pos
    self.pos = self.pos+n
    return self.str:sub(startpos, self.pos-1)
end

-- skip a byte
function streamreader:skip8()
    self.pos = self.pos+1
end

-- skip a word
function streamreader:skip16()
    self.pos = self.pos+2
end

-- skip a long
function streamreader:skip32()
    self.pos = self.pos+4
end

-- skip N number of bytes
function streamreader:skipN(n)
    self.pos = self.pos+n
end

-- return current position
function streamreader:getpos()
    return self.pos
end

-- set current position
function streamreader:setpos(n)
    self.pos = n
end

-- get if we are at the end of string
function streamreader:eos()
    if self.pos >= #self.str then return true else return false end
end


return streamreader