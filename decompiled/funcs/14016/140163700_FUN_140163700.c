// Address: 0x140163700
// Ghidra name: FUN_140163700
// ============ 0x140163700 FUN_140163700 (size=199) ============


undefined8 FUN_140163700(longlong param_1)



{

  longlong *plVar1;

  longlong lVar2;

  longlong *plVar3;

  undefined8 uVar4;

  

  lVar2 = FUN_14017ffb0();

  uVar4 = 1;

  FUN_140179b40(DAT_1403fc348);

  plVar3 = (longlong *)0x0;

  plVar1 = DAT_1403fc350;

  do {

    if (plVar1 == (longlong *)0x0) {

      if (param_1 != 0) {

        plVar3 = (longlong *)FUN_1401841f0(0x18);

        if (plVar3 == (longlong *)0x0) {

          uVar4 = 0;

        }

        else {

          plVar3[2] = (longlong)DAT_1403fc350;

          *plVar3 = lVar2;

          plVar3[1] = param_1;

          DAT_1403fc350 = plVar3;

        }

      }

LAB_1401637a7:

      FUN_140179b60(DAT_1403fc348);

      return uVar4;

    }

    if (*plVar1 == lVar2) {

      if (param_1 == 0) {

        if (plVar3 == (longlong *)0x0) {

          DAT_1403fc350 = (longlong *)plVar1[2];

          FUN_1401841e0();

        }

        else {

          plVar3[2] = plVar1[2];

          FUN_1401841e0();

        }

      }

      else {

        plVar1[1] = param_1;

      }

      goto LAB_1401637a7;

    }

    plVar3 = plVar1;

    plVar1 = (longlong *)plVar1[2];

  } while( true );

}




