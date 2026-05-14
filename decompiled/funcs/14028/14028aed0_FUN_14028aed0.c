// Address: 0x14028aed0
// Ghidra name: FUN_14028aed0
// ============ 0x14028aed0 FUN_14028aed0 (size=91) ============


undefined8 FUN_14028aed0(ushort *param_1)



{

  ushort uVar1;

  undefined8 uVar2;

  

  uVar1 = *param_1;

  if ((((uVar1 != 2) &&

       (((0x20 < uVar1 || ((0x100010110U >> ((ulonglong)uVar1 & 0x3f) & 1) == 0)) && (uVar1 != 0x80)

        ))) && (((uVar1 != 0x100 && (uVar1 != 0x400)) && (uVar1 != 1)))) && (uVar1 != 0x40)) {

    return 0;

  }

  uVar2 = FUN_14028c030(param_1 + 2);

  return uVar2;

}




