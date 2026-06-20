local days = {"Sunday", "Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday"}

print(days[1])

local a = {x = 10, y = 20}

print(type(a));

t = {10, print, x = 12, k = "hi"}
for k, v in pairs(t) do
  print(k, v);
end

print('-----')
t = {10, print, 12, "hi"}
for k = 1, #t do
  print(k, t[k])
end

print(type(t))
print("the length of table is " .. #t)
table.insert(t, 2,"mutter")
for k = 1, #t do
  print(k, t[k])
end


function add (a)
  local sum = 0
  for i = 1, #a do
    sum = sum + a[i]
  end
  return sum
end

local c = {12, 88 ,19, 73}
print(add(c))


function f (a, b) print(a, b) end;
f()
f('q')
f(2, 'c')
f(2, 'c', 'b')

function multiret()
  return 2, 8, 10;
end

local c , a= multiret();
print(c, a)

function foo0() end
function foo1() return 'a' end
function foo2() return 'a', 'b' end

print(foo0())
print(foo1())
print(foo2())
print(foo2(), 8)
print(foo2() .. 'b')


function add (...)
  local s = 0
  for _, v in ipairs{...} do
    s = s + v
  end
  return s
end

function myadd(...)
  local sum = 0
  for i, v, z in ipairs{...} do
    print(i, v, z)
    sum = sum + v;
  end
  return sum
end

print(myadd(3, 4, 10, 25, 12))

function foo1 (...)
  print("calling foo:", ...)
  return foo(...)
end

print(select(1, "a", "b", "c"))
print(select(2, "a", "b", "c"))

function nonils (...)
  local arg = table.pack(...)
  for i = 1, arg.n do
    if arg[i] == nil then return false end
  end
  return true
end

print(nonils(2,3,nil))
print(nonils(2,3, 'tt'))

print(table.unpack({1,8,9,1,7, 3}))

print(table.unpack({2, 8, 0, 6}, 1, 1))

-- local bad
-- t = io.read("a")
-- t = string.gsub(t, "bad", "good")
-- io.write(t)

-- t = io.read("all")
-- t = string.gsub(t, "([\128-\255=])", function (c)
-- return string.format("=%02X", string.byte(c))
-- end)
-- io.write(t)

-- local count = 0
-- for line in io.lines() do
-- count = count + 1
-- io.write(string.format("%6d ", count), line, "\n")
-- end

-- local lines = {}

-- for line in io.lines() do
-- lines[#lines + 1] = line
-- end

-- table.sort(lines, function(a, b) return a < b end)

-- for _, i in ipairs(lines) do
-- io.write(i, "\n")
-- end

-- while true do
-- local block = io.read(2^10) -- read 1kb
-- if not block then break end
-- io.write(block)
-- end

-- while true do
-- local n1, n2, n3 = io.read("n", "n", "n")
-- if not n1 then break end
-- print(math.max(n1, n2, n3))
-- end
print(io.open("non-existent-file", "r"))

print(io.open("/etc/passwd", "r+"))

print(io.popen("/usr/bin/bash"), "w")
local t = io.tmpfile()
t.write(t,"a line in the tempfile")


io.stderr:write("message","\n")


print(os.getenv("HOME"))

function createDir(dirname)
  os.execute("mkdir " .. dirname)
end

os.execute("pwd")

local a, b = 1 , 11;

print(a, b)

if a < b then
  print(a,b)
  local n, m = 111, 37;
  print(n, m)
end
print(n, m)

if a < b then
  print('a')
else
  print('b')
end

if a < b then
  --do something
elseif a > b then
  --do other something
else
end


while false do
end

local i = 1;
while a[i] do

end

repeat
  -- do something
until i == 1

function L(...)
  for i in ipairs(...) do -- for table
  end
end
