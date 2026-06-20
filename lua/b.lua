
network = {
  {name = "grauna", IP = "210.26.30.34"},
  {name = "arraial", IP = "210.26.30.23"},
  {name = "lua", IP = "210.26.23.12"},
  {name = "derain", IP = "210.26.23.20"},
}
print(type(network))
table.sort(network, function (a,b) return (a.name > b.name) end)

for k, m in ipairs(network) do
  print(m.name, m.IP)
end


function derivative(f, delta)
  delta = delta or 1e-4
  return function(x)
    return (f(x + delta) - f(x) )/ delta
  end
end

-- Closures
Lib = {}
Lib.foo = function (x,y) return x + y end
