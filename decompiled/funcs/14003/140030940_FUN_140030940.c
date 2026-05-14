// Address: 0x140030940
// Ghidra name: FUN_140030940
// ============ 0x140030940 FUN_140030940 (size=528) ============


undefined8 * FUN_140030940(undefined8 *param_1)



{

  int iVar1;

  int iVar2;

  

  FUN_1400c9420();

  *param_1 = &PTR_FUN_1403037d0;

  param_1[0x4c] = 0;

  param_1[0x4d] = 0;

  param_1[0x4e] = 0;

  param_1[0x54] = 0;

  param_1[0x55] = 0;

  param_1[0x56] = 0;

  param_1[0xcf] = 0;

  param_1[0xd0] = 0;

  param_1[0xd1] = 0;

  FUN_1400278e0(param_1 + 3,"Normal Suburban House");

  FUN_1400278e0(param_1 + 7,"Biohacker");

  FUN_1400cf540(param_1,1,0,DAT_140303398,DAT_140303398,DAT_140303398);

  FUN_1400c9f10(param_1);

  FUN_1400c9c30(param_1,7,0xc5,0x50,0xc,0xc,1);

  FUN_1400c9c30(param_1,8,0x136,0x56,5,5,1);

  iVar1 = 0xe;

  iVar2 = 9;

  do {

    FUN_1400c9c30(param_1,iVar2,0xc0,iVar1,0x2e,0xb,0x21);

    iVar1 = iVar1 + 0xc;

    iVar2 = iVar2 + 1;

  } while (iVar1 < 0x3e);

  param_1[0x4b] = 0;

  FUN_1400cf540(param_1,3,DAT_140303fd4,DAT_14030338c,DAT_14030374c,DAT_14030338c);

  FUN_1400cf540(param_1,4,DAT_140303fc8,DAT_140303394,DAT_14039ca38,DAT_14039ca38);

  *(undefined4 *)(param_1 + 0x4a) = 0;

  param_1[0xd3] = 0x106;

  param_1[0xd4] = 0;

  *(undefined2 *)(param_1 + 0xd6) = 0;

  FUN_140032320(param_1);

  return param_1;

}




