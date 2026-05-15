// Address: 0x14020e410
// Ghidra name: FUN_14020e410
// ============ 0x14020e410 FUN_14020e410 (size=56) ============


ulonglong FUN_14020e410(int param_1)



{

  int3 iVar1;

  ulonglong in_RAX;

  int7 iVar2;

  uint uVar4;

  int7 iVar3;

  

  uVar4 = param_1 - 1;

  if (uVar4 < 8) {

    iVar1 = (int3)(uVar4 >> 8);

    iVar2 = (int7)iVar1;

    iVar3 = (int7)iVar1;

    switch(uVar4) {

    case 0:

      return CONCAT71(iVar3,1);

    case 1:

      return CONCAT71(iVar3,3);

    case 2:

      return CONCAT71(iVar3,2);

    case 3:

      return CONCAT71(iVar3,6);

    case 4:

      return CONCAT71(iVar2,4);

    case 5:

      return CONCAT71(iVar2,0xc);

    case 6:

      return CONCAT71(iVar2,8);

    case 7:

      return CONCAT71(iVar2,9);

    }

  }

  return in_RAX & 0xffffffffffffff00;

}




