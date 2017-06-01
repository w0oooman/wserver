

--开服
function OnServerStart()
    local t = 3
    if not t then
        t = 2
    end

    Log("OnServerStart")
    return 1
end

--关服
function OnServerDwon()
    Log("OnServerDwon")
end

--每一分钟回调
function SI_EachOneMinute()
    Log("SI_EachOneMinute")
    
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