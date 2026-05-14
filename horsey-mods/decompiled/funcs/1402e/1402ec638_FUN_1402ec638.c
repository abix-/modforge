// Address: 0x1402ec638
// Ghidra name: FUN_1402ec638
// ============ 0x1402ec638 FUN_1402ec638 (size=132) ============


undefined1 FUN_1402ec638(void)



{

  int iVar1;

  longlong lVar2;

  undefined1 uVar3;

  

  iVar1 = FUN_1402ec9ac();

  uVar3 = 0;

  if ((iVar1 == 1) && (DAT_1404240b0 != -1)) {

    if ((DAT_1404240b0 == 0) &&

       (lVar2 = FUN_1402ec028(0x16,"MessageBoxA",&DAT_14038eae0,"MessageBoxA"), lVar2 == 0)) {

      return 0;

    }

    uVar3 = 0;

    if (DAT_1404240b8 != -1) {

      if ((DAT_1404240b8 == 0) &&

         (lVar2 = FUN_1402ec028(0x17,"MessageBoxW",&DAT_14038eaf8,"MessageBoxW"), lVar2 == 0)) {

        return 0;

      }

      uVar3 = 1;

    }

  }

  return uVar3;

}




