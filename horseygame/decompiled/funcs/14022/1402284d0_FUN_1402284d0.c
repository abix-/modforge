// Address: 0x1402284d0
// Ghidra name: FUN_1402284d0
// ============ 0x1402284d0 FUN_1402284d0 (size=97) ============


undefined8 FUN_1402284d0(longlong param_1)



{

  int iVar1;

  longlong lVar2;

  

  if (param_1 == 0) {

    iVar1 = GetSystemMetrics(0x1000);

    if ((iVar1 == 0) || (param_1 = DAT_1403fdc70, DAT_1403fdc70 == 0)) {

      DAT_1403fdc68 = (HCURSOR)0x0;

      goto LAB_14022850c;

    }

  }

  if (*(int *)(*(undefined8 **)(param_1 + 8) + 3) < 1) {

    DAT_1403fdc68 = (HCURSOR)**(undefined8 **)(param_1 + 8);

  }

  else {

    DAT_1403fdc68 = (HCURSOR)FUN_140227610();

  }

LAB_14022850c:

  lVar2 = FUN_140161230();

  if (lVar2 != 0) {

    SetCursor(DAT_1403fdc68);

  }

  return 1;

}




