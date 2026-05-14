// Address: 0x140192a60
// Ghidra name: FUN_140192a60
// ============ 0x140192a60 FUN_140192a60 (size=165) ============


undefined8 FUN_140192a60(short param_1,short param_2,longlong param_3)



{

  longlong *plVar1;

  int iVar2;

  longlong *plVar3;

  undefined8 uVar4;

  longlong *plVar5;

  

  plVar3 = (longlong *)FUN_1401926f0();

  uVar4 = 0;

  plVar5 = plVar3;

  if (plVar3 != (longlong *)0x0) {

    do {

      if ((((short)plVar5[1] == param_1) && (*(short *)((longlong)plVar5 + 10) == param_2)) &&

         ((param_3 == 0 || ((plVar5[2] != 0 && (iVar2 = FUN_14012fbc0(param_3), iVar2 == 0)))))) {

        if (*plVar5 != 0) {

          uVar4 = FUN_140192b10();

          goto LAB_140192acf;

        }

        break;

      }

      plVar1 = plVar5 + 7;

      plVar5 = (longlong *)*plVar1;

    } while ((longlong *)*plVar1 != (longlong *)0x0);

    FUN_140196b40(L"Device with requested VID/PID/(SerialNumber) not found");

    uVar4 = 0;

LAB_140192acf:

    FUN_1401929b0(plVar3);

  }

  return uVar4;

}




