
-- 深拷贝函数
function deepcopy(orig)
    local orig_type = type(orig)
    local copy
    if orig_type == 'table' then
        copy = {}
        for orig_key, orig_value in next, orig, nil do
            copy[deepcopy(orig_key)] = deepcopy(orig_value)
        end
        setmetatable(copy, deepcopy(getmetatable(orig)))
    else -- number, string, boolean, etc
        copy = orig
    end
    return copy
end

-- 安全移除lua数组(key从1开始且连续)元素
function RemoveLuaArrayData(tab, func, ...)
	if type(tab) == _typetable and type(func) == _typefunc then
		local j = 1
		for i = j, #tab do
			if func(tab[j], ...) == true then
				_tableremove(tab, j)
			else
			    j = j + 1
			end
		end
	end
end

--获取LUA中字符转换后长度(中文占3个字节,当作占2个字节后的长度)
function GetLuaStrConvertLen(str)
	local s = tostring(str)
	local len = string.len(s)

	local num = 0
	for i=1,len do
		local ascii = string.byte(s,i)
		if ascii>127 then
	        num = num + 1
		end
    end
	
	len = len - num
	if num%3 == 0 then  --LUA中汉字占3个字节
		num = num/3*2   --配置中常认为1个汉字占2个字节,所以转换一下
	else
	    num = math.ceil(num/3)
	end
	
	return len+num
end