function split(s, delimiter)
    result = {}
    for match in (s..delimiter):gmatch("(.-)"..delimiter) do
        table.insert(result, match)
    end
    return result
end

local canvas_line = love.graphics.newCanvas(640, 32)
local canvas = love.graphics.newCanvas(640, 480)

function love.load(arg)
        
    -- load font
    local font = love.graphics.newFont("/fonts/Doom.ttf", 16)
    love.graphics.setFont(font)
    
    -- read credits file
    local file_credits = io.open(love.filesystem.getSourceBaseDirectory() .. "/src/credits.txt")
    local credits_list = {}
    
    file_credits:read("*line")
    file_credits:read("*line")
    file_credits:read("*line")
    file_credits:read("*line")
    local line = file_credits:read("*line")
    
    local linepos = 0
    
    
    canvas = love.graphics.newCanvas(640, 1900)
    love.graphics.setCanvas(canvas)
        love.graphics.clear(0, 0, 0, 255)
    love.graphics.setCanvas()    
    
    local j = 0
    local j2 = 0
    -- for each line
    while line ~= nil do
        
        if j == 0 then
            linepos = linepos + font:getHeight()
        end
        
        canvas_line = love.graphics.newCanvas(font:getWidth(line), 32)
    
        love.graphics.setCanvas(canvas_line)

            -- clear out previous line
            love.graphics.clear(0, 0, 0, 0)

            -- reset color to white
            love.graphics.setColor(255, 255, 255, 255)

            local r = line:sub(1, 1)*28
            local g = line:sub(2, 2)*28
            local b = line:sub(3, 3)*28
            j = line:sub(4, 4)*1
            love.graphics.setColor(r, g, b, 255)
            love.graphics.print(line:sub(6))
 
        love.graphics.setCanvas()
   
        -- apply formatted line to canvas
        love.graphics.setCanvas(canvas)
        
            local x = 320-font:getWidth(line)/2
            local y = linepos
            
            if j2 == 1 then
                x = 280
                j2 = 0
            end
            if j == 1 then
                x = 280-font:getWidth(line)
                j2 = 1
            end

            love.graphics.setColor(255, 255, 255, 255)
            love.graphics.draw(canvas_line, x, y)
            
        love.graphics.setCanvas()   
   
        line = file_credits:read("*line")
    end
    file_credits:close()
    
    local imgdata = canvas:newImageData()
    local pngdata = imgdata:encode("png"):getString()
    local pngfile = io.open(love.filesystem.getSourceBaseDirectory() .. "/src/results/LCREDITS.png", "w+b")
    pngfile:write(pngdata)
    pngfile:close()
    
end



function love.update(dt)
    
end



function love.draw()
    love.graphics.setColor(255, 255, 255, 255)
    love.graphics.draw(canvas)
end


















