// Address: 0x14007de20
// Ghidra name: FUN_14007de20
// ============ 0x14007de20 FUN_14007de20 (size=514) ============


undefined8 FUN_14007de20(longlong param_1)



{

  float fVar1;

  longlong lVar2;

  longlong *plVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  ulonglong uVar8;

  

  FUN_1400d0a00(param_1,0);

  FUN_1400cd5a0(param_1,1);

  FUN_1400ce540(param_1,0);

  if (*(longlong *)(param_1 + 0x148) == 0) goto LAB_14007e008;

  iVar4 = *(int *)(param_1 + 0x308);

  if (0 < iVar4) {

    *(undefined1 *)(param_1 + 0x264) = 1;

  }

  else {

    *(undefined1 *)(param_1 + 0x264) = 0;

  }

  *(bool *)(param_1 + 0x278) = 0 < iVar4;

  *(bool *)(param_1 + 0x28c) = 0 < iVar4;

  *(bool *)(param_1 + 0x2a0) = 0 < iVar4;

  *(undefined1 *)(param_1 + 0x2b4) = 1;

  *(bool *)(param_1 + 0x2c8) = 0 < iVar4;

  *(bool *)(param_1 + 0x2dc) = 0 < iVar4;

  iVar5 = 0;

  *(bool *)(param_1 + 0x2f0) = 0 < iVar4;

  iVar7 = 0;

  plVar3 = *(longlong **)(param_1 + 0xb8);

  iVar6 = 0;

  uVar8 = *(longlong *)(param_1 + 0xc0) - (longlong)plVar3 >> 3;

  if (uVar8 == 0) {

LAB_14007df48:

    if (0 < iVar4) {

      lVar2 = FUN_1400cc9d0(param_1,1);

      *(undefined1 *)(lVar2 + 0x10) = 0;

      *(undefined4 *)(lVar2 + 0x44) = 0xffffffff;

    }

  }

  else {

    do {

      lVar2 = *plVar3;

      if (*(int *)(lVar2 + 8) == 3) {

        if ((DAT_14030ac70 - *(float *)(lVar2 + 0x2c) < *(float *)(lVar2 + 0x28)) &&

           (*(float *)(lVar2 + 0x28) < DAT_14030ac74 - *(float *)(lVar2 + 0x2c))) {

          if (*(int *)(lVar2 + 0xc) == 1) {

            iVar7 = iVar7 + 1;

          }

          else if (*(int *)(lVar2 + 0xc) == 0) {

            iVar5 = iVar5 + 1;

          }

        }

      }

      iVar6 = iVar6 + 1;

      plVar3 = plVar3 + 1;

    } while ((ulonglong)(longlong)iVar6 < uVar8);

    if (iVar7 == 0) goto LAB_14007df48;

  }

  fVar1 = DAT_140303354;

  if (iVar5 == 0) {

    iVar5 = 0x8a;

    iVar4 = 0x5e;

    do {

      lVar2 = FUN_1400cc9d0(param_1,0,(float)(iVar4 + -10) * fVar1,(float)(iVar5 + -2) * fVar1);

      *(undefined1 *)(lVar2 + 0x10) = 0;

      lVar2 = FUN_1400cc9d0(param_1,0,(float)iVar4 * fVar1,(float)iVar5 * fVar1);

      iVar5 = iVar5 + -10;

      iVar4 = iVar4 + 10;

      *(undefined1 *)(lVar2 + 0x10) = 0;

    } while (0x62 < iVar5);

  }

LAB_14007e008:

  *(undefined8 *)(param_1 + 0x2f4) = 0;

  *(undefined1 *)(param_1 + 0x250) = 0;

  return 1;

}




