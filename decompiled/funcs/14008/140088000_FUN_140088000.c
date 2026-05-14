// Address: 0x140088000
// Ghidra name: FUN_140088000
// ============ 0x140088000 FUN_140088000 (size=775) ============


undefined8 * FUN_140088000(undefined8 *param_1)



{

  longlong lVar1;

  undefined4 uVar2;

  int iVar3;

  int iVar4;

  float fVar5;

  

  FUN_1400c9420();

  *param_1 = &PTR_FUN_14030b050;

  param_1[0x94] = 0;

  param_1[0x95] = 0;

  param_1[0x96] = 0;

  param_1[0x97] = 0;

  param_1[0x98] = 0;

  param_1[0x99] = 0;

  FUN_1400278e0(param_1 + 3,"CRISPR Lab");

  FUN_1400278e0(param_1 + 7,"Crispr");

  *(undefined4 *)(param_1 + 0xb) = DAT_1403d9e20;

  FUN_1400c9f10(param_1);

  FUN_1400c9c30(param_1,7,0xac,0x41,0xe,0xe,1);

  FUN_1400c9c30(param_1,8,0x79,0x4e,0x10,0x10,1);

  FUN_1400c9c30(param_1,9,0x108,0x40,0x18,0x13,1);

  FUN_1400c9c30(param_1,10,0x128,0x58,0x10,8,1);

  iVar4 = 0xc;

  FUN_1400c9c30(param_1,0xb,0x7c,4,0x48,0xc,1);

  iVar3 = 0x22;

  do {

    FUN_1400c9c30(param_1,iVar4,0xfd,iVar3,0x2e,0xb,0x21);

    iVar3 = iVar3 + 0xb;

    iVar4 = iVar4 + 1;

  } while (iVar3 < 0x43);

  FUN_1400cf540(param_1,1,0,DAT_140303398,DAT_140303398,DAT_140303398);

  FUN_1400cf540(param_1,2,DAT_14039ca80,DAT_14039ca44,DAT_14030339c,DAT_140303394);

  uVar2 = DAT_140309bf0;

  FUN_1400cf540(param_1,3,DAT_14030b61c,DAT_140309bf0,DAT_14030374c,DAT_14030374c);

  FUN_1400cf540(param_1,4,DAT_140303fd0,uVar2,uVar2,DAT_140303388);

  lVar1 = param_1[0xf];

  fVar5 = *(float *)(lVar1 + 0x3c) * DAT_14039ca34 + *(float *)(lVar1 + 0x34) + DAT_140303354;

  *(float *)(param_1 + 0x4d) = *(float *)(lVar1 + 0x38) * DAT_14039ca34 + *(float *)(lVar1 + 0x30);

  *(float *)((longlong)param_1 + 0x26c) = fVar5;

  param_1[0x4e] = 0;

  *(undefined4 *)((longlong)param_1 + 0x25c) = 1;

  *(undefined1 *)(param_1 + 0x90) = 1;

  *(undefined2 *)((longlong)param_1 + 0x491) = 0x100;

  *(undefined1 *)(param_1 + 0x92) = 0;

  return param_1;

}




