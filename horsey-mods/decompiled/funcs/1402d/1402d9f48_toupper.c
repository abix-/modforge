// Address: 0x1402d9f48
// Ghidra name: toupper
// ============ 0x1402d9f48 toupper (size=42) ============


/* Library Function - Single Match

    toupper

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



int __cdecl toupper(int _C)



{

  uint uVar1;

  undefined4 in_register_0000000c;

  ulonglong uVar2;

  

  uVar2 = CONCAT44(in_register_0000000c,_C);

  if (DAT_1403ff13c == 0) {

    if (_C - 0x61U < 0x1a) {

      uVar2 = (ulonglong)(_C - 0x20);

    }

  }

  else {

    uVar1 = FUN_1402d9de8(uVar2,0);

    uVar2 = (ulonglong)uVar1;

  }

  return (int)uVar2;

}




