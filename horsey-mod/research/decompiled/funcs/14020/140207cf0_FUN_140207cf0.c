// Address: 0x140207cf0
// Ghidra name: FUN_140207cf0
// ============ 0x140207cf0 FUN_140207cf0 (size=107) ============


undefined8 FUN_140207cf0(short param_1,short param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  

  uVar2 = 0;

  FUN_140159d30();

  lVar1 = DAT_1403fd198;

  do {

    if (lVar1 == 0) {

LAB_140207d43:

      FUN_14015bb10();

      return uVar2;

    }

    if ((param_1 == *(short *)(lVar1 + 0x20)) && (param_2 == *(short *)(lVar1 + 0x22))) {

      if (*(longlong *)(lVar1 + 0x10) != 0) {

        uVar2 = FUN_14012f0d0();

      }

      goto LAB_140207d43;

    }

    lVar1 = *(longlong *)(lVar1 + 0xb8);

  } while( true );

}




