def main : IO Unit := do
  let stdin ← IO.getStdin
  let stdout ← IO.getStdout

  stdout.putStrLn "¿Cómo quieres que te llame?"
  let input ← stdin.getLine
  let name := input.dropEndWhile Char.isWhitespace

  stdout.putStrLn s!"Hola, {name}!"
