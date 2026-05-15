// Address: 0x14021b070
// Ghidra name: FUN_14021b070
// ============ 0x14021b070 FUN_14021b070 (size=86) ============


undefined8 FUN_14021b070(longlong param_1)



{

  longlong *plVar1;

  undefined8 uVar2;

  

  uVar2 = 0;

  FUN_140179b40(DAT_1403fdb78);

  plVar1 = DAT_1403fdb70;

  do {

    if (plVar1 == (longlong *)0x0) {

LAB_14021b0ab:

      FUN_140179b60(DAT_1403fdb78);

      return uVar2;

    }

    if (*plVar1 == param_1) {

      uVar2 = 1;

      goto LAB_14021b0ab;

    }

    plVar1 = (longlong *)plVar1[1];

  } while( true );

}




