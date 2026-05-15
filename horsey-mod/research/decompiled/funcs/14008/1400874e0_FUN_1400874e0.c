// Address: 0x1400874e0
// Ghidra name: FUN_1400874e0
// ============ 0x1400874e0 FUN_1400874e0 (size=205) ============


void FUN_1400874e0(longlong param_1,longlong param_2)



{

  float fVar1;

  longlong *plVar2;

  longlong lVar3;

  int iVar4;

  longlong lVar5;

  

  iVar4 = 0;

  lVar3 = *(longlong *)(param_2 + 0x18);

  if (*(longlong *)(param_2 + 0x20) - lVar3 >> 5 != 0) {

    lVar5 = 0;

    do {

      plVar2 = (longlong *)(lVar5 + lVar3);

      fVar1 = *(float *)(param_2 + 0x14);

      if (0xf < *(ulonglong *)(lVar5 + 0x18 + lVar3)) {

        plVar2 = (longlong *)*plVar2;

      }

      FUN_140086570(param_1,lVar3,

                    (float)iVar4 * fVar1 * (float)*(int *)(param_1 + 0xc) +

                    (float)*(int *)(param_1 + 4) * fVar1,0,fVar1,*(undefined4 *)(param_2 + 0x10),

                    plVar2);

      lVar3 = *(longlong *)(param_2 + 0x18);

      iVar4 = iVar4 + 1;

      lVar5 = lVar5 + 0x20;

    } while ((ulonglong)(longlong)iVar4 < (ulonglong)(*(longlong *)(param_2 + 0x20) - lVar3 >> 5));

  }

  return;

}




