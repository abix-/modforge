// Address: 0x140080b00
// Ghidra name: FUN_140080b00
// ============ 0x140080b00 FUN_140080b00 (size=117) ============


undefined8 FUN_140080b00(longlong param_1,float param_2)



{

  longlong lVar1;

  undefined7 uVar2;

  float fVar3;

  

  lVar1 = *(longlong *)(param_1 + 0x80);

  uVar2 = (undefined7)((ulonglong)lVar1 >> 8);

  if (*(int *)(lVar1 + 0x24c) != 2) {

    if (*(int *)(lVar1 + 0x24c) != 1) {

      param_2 = param_2 * DAT_14039ca38;

    }

    return CONCAT71(uVar2,*(float *)(lVar1 + 0x158) <= param_2);

  }

  fVar3 = DAT_14039ca44;

  if ((*(uint *)(lVar1 + 600) & 0x800000) == 0) {

    fVar3 = 0.0;

  }

  return CONCAT71(uVar2,*(float *)(lVar1 + 0x158) + *(float *)(lVar1 + 0x158) +

                        *(float *)(lVar1 + 0x148) + *(float *)(lVar1 + 0x148) + fVar3 <

                        param_2 * DAT_14039ca34);

}




