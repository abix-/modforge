// Address: 0x1400dbb00
// Ghidra name: FUN_1400dbb00
// ============ 0x1400dbb00 FUN_1400dbb00 (size=411) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1400dbb00(longlong param_1)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  longlong lVar4;

  uint uVar5;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 local_10;

  

  uVar3 = DAT_14039ca34;

  uVar2 = DAT_140304be0;

  uVar1 = DAT_14030374c;

  *(undefined4 *)(param_1 + 0x114) = 0x41800000;

  *(float *)(param_1 + 0x118) = (float)DAT_14030b680 * DAT_140303354;

  *(float *)(param_1 + 0x11c) = (float)DAT_14030b684 * DAT_140303354;

  FUN_1400cf540(param_1,3,uVar3,uVar1,DAT_14030fc10,uVar2);

  FUN_1400cf540(param_1,5,

                (float)((double)((float)DAT_14030b680 / *(float *)(param_1 + 0x114)) -

                       _DAT_140304ba8),DAT_14030374c,DAT_140303398,DAT_14030338c);

  uVar5 = DAT_140303380;

  FUN_1400cf540(param_1,2,DAT_14039ca44,

                (float)((double)(*(float *)(*(longlong *)(param_1 + 0x78) + 0x3c) +

                                *(float *)(*(longlong *)(param_1 + 0x78) + 0x34)) + DAT_140304b98),

                DAT_140303750,DAT_140303380);

  uStack_20 = 0;

  local_18 = 5;

  local_10 = 0xf;

  local_28 = (ulonglong)CONCAT14(DAT_14030f124,DAT_14030f120);

  lVar4 = FUN_1400c9e00(param_1,2,&local_28,0x90,4,uVar5 & 0xffffff00,0,1);

  *(float *)(lVar4 + 0x3c) = *(float *)(lVar4 + 0x3c) + DAT_140304c00;

  return;

}




