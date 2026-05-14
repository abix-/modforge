// Address: 0x140263320
// Ghidra name: FUN_140263320
// ============ 0x140263320 FUN_140263320 (size=198) ============


undefined8 FUN_140263320(longlong *param_1,undefined8 param_2)



{

  longlong lVar1;

  uint uVar2;

  longlong *plVar3;

  uint uVar4;

  

  uVar2 = 0;

  uVar4 = 0;

  plVar3 = param_1;

  do {

    lVar1 = FUN_140263170(&PTR_DAT_14037db90 + (longlong)(int)uVar4 * 5,param_2,0);

    *plVar3 = lVar1;

    if (lVar1 == 0) goto LAB_1402633c0;

    uVar4 = uVar4 + 1;

    plVar3 = plVar3 + 1;

  } while (uVar4 < 3);

  plVar3 = param_1 + 3;

  do {

    if (uVar2 != 4) {

      lVar1 = FUN_140263170(&PTR_DAT_14037dc10 + (longlong)(int)uVar2 * 5,param_2,1);

      *plVar3 = lVar1;

      if (lVar1 == 0) {

LAB_1402633c0:

        FUN_1402633f0(param_1,param_2);

        return 0;

      }

    }

    uVar2 = uVar2 + 1;

    plVar3 = plVar3 + 1;

    if (4 < uVar2) {

      return 1;

    }

  } while( true );

}




