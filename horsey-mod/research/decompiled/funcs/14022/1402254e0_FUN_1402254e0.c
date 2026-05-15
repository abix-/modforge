// Address: 0x1402254e0
// Ghidra name: FUN_1402254e0
// ============ 0x1402254e0 FUN_1402254e0 (size=121) ============


undefined8 FUN_1402254e0(longlong param_1)



{

  undefined8 uVar1;

  int iVar2;

  longlong *plVar3;

  

  iVar2 = 0;

  if (0 < DAT_1403fdc40) {

    plVar3 = &DAT_1403fdc00;

    do {

      if (*plVar3 == param_1) {

        uVar1 = (&DAT_1403fdc08)[(longlong)iVar2 * 2];

        if (iVar2 != 0) {

          FUN_1402f8e20(&DAT_1403fdc10,&DAT_1403fdc00);

          DAT_1403fdc00 = param_1;

          DAT_1403fdc08 = uVar1;

        }

        return uVar1;

      }

      iVar2 = iVar2 + 1;

      plVar3 = plVar3 + 2;

    } while (iVar2 < DAT_1403fdc40);

  }

  return 0;

}




