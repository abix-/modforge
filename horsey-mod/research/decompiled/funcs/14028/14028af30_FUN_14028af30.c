// Address: 0x14028af30
// Ghidra name: FUN_14028af30
// ============ 0x14028af30 FUN_14028af30 (size=86) ============


ushort FUN_14028af30(ushort *param_1)



{

  ushort uVar1;

  ushort uVar2;

  

  uVar1 = *param_1;

  if ((((uVar1 == 2) ||

       (((uVar1 < 0x21 && ((0x100010110U >> ((ulonglong)uVar1 & 0x3f) & 1) != 0)) || (uVar1 == 0x80)

        ))) || (((uVar1 == 0x100 || (uVar1 == 0x400)) || (uVar1 == 1)))) ||

     (uVar2 = 0, uVar1 == 0x40)) {

    uVar2 = param_1[0xc];

  }

  return uVar2;

}




