
local function serialize (obj)
    local lua = ""  
    local t = type(obj)  
    if t == "number" then  
        lua = lua .. obj  
    elseif t == "boolean" then  
        lua = lua .. tostring(obj)  
    elseif t == "string" then  
        lua = lua .. string.format("%q", obj)  
    elseif t == "table" then  
        lua = lua .. "{"
        for k, v in pairs(obj) do  
            lua = lua .. "[" .. serialize(k) .. "]=" .. serialize(v) .. ","  
        end  
        local metatable = getmetatable(obj)  
        if metatable ~= nil and type(metatable.__index) == "table" then  
            for k, v in pairs(metatable.__index) do  
                lua = lua .. "[" .. serialize(k) .. "]=" .. serialize(v) .. ","  
            end
        end
        lua = lua .. "}"  
    elseif t == "nil" then  
        return "nil"  
    elseif t == "userdata" then
        return "userdata"
    elseif t == "function" then
        return "function"
    else  
        error("can not serialize a " .. t .. " type.")
    end  
    return lua
end

local function unserialize(str)
    local func_str = "return "..str
    local func = load(func_str)
    return func()
end

local function stest()
    look("stest -------------")
    local msg_str = "heheha"
    local len = 2 + #msg_str
    local data = string.pack(">Hs2", len, msg_str)
    local lenTmp,dataTmp,xxx,yyy = string.unpack(">Hs2", data)
    look(lenTmp)
    look(dataTmp)
    look(xxx)
    look(yyy)
    look("------------")
    local tabTest = {1, 3, att = "hehehahak", b = "gg"}
    local res = serialize(tabTest)
    look(res)
    look(unserialize(res))  
end

--开服
function OnServerStart()
    local t = 3
    if not t then
        t = 2
    end

    Log("OnServerStart")
    stest()

    return 1
end

--关服
function OnServerDwon()
    Log("OnServerDwon")
	local a = 1+c
end

--每一分钟回调
function SI_EachOneMinute()
    Log("SI_EachOneMinute")
	OnServerDwon()
    -- local temp = {"a","b","c","d","g","h","i","x","y","z","m","n","o","p","q"}
    -- local rand = math.random(#temp)
    -- local a = "abcde"..temp[rand]
    -- if a == type("") then
    -- 	local b = 1
    -- 	local c = b
    -- 	local t = {1,2,3}
    -- end
    -- a = nil
end

--每十分钟回调
function SI_EachTenMinute()
	Log("SI_EachTenMinute")
end

--每一小时回调
function SI_EachOneHour()
	Log("SI_EachOneHour")
end

function function_test(a,b)
	Log("function_test")
	Log(a)
	Log(b)
end