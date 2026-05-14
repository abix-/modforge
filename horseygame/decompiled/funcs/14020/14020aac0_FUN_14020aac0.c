// Address: 0x14020aac0
// Ghidra name: FUN_14020aac0
// ============ 0x14020aac0 FUN_14020aac0 (size=246) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14020aac0(void)



{

  int iVar1;

  longlong lVar2;

  

  _DAT_1403fd240 = _DAT_1403fd240 + -1;

  if ((_DAT_1403fd240 == 0) && (DAT_1403fd23c != '\0')) {

    iVar1 = 0;

    if (0 < DAT_1403fd238) {

      lVar2 = 0;

      do {

        (**(code **)(*(longlong *)**(undefined8 **)(lVar2 + DAT_1403fd230) + 0x10))();

        iVar1 = iVar1 + 1;

        lVar2 = lVar2 + 8;

      } while (iVar1 < DAT_1403fd238);

    }

    if (DAT_1403fd230 != 0) {

      FUN_1401841e0();

      DAT_1403fd230 = 0;

    }

    DAT_1403fd238 = 0;

    if (DAT_1403fd248 != (longlong *)0x0) {

      (**(code **)(*DAT_1403fd248 + 0x38))(DAT_1403fd248,DAT_1403fd250);

      (**(code **)(*DAT_1403fd248 + 0x48))(DAT_1403fd248,DAT_1403fd258);

      (**(code **)(*DAT_1403fd248 + 0x10))();

      DAT_1403fd248 = (longlong *)0x0;

    }

    FUN_1401a9ea0();

    DAT_1403fd23c = '\0';

  }

  return;

}




