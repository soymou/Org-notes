def main : IO Unit := do
  let proc ← IO.Process.spawn {
    cmd := "sudo"
    args := #["-S", "rm", "/home/mou/Desktop/Personal/Org/Lean/test.lean"]
    stdin := IO.Process.Stdio.inherit
    stderr := IO.Process.Stdio.inherit
  }
SYSTEM32/winload.efi
