// Address: 0x1400c9f10
// Ghidra name: FUN_1400c9f10
// ============ 0x1400c9f10 FUN_1400c9f10 (size=189) ============


longlong FUN_1400c9f10(void)



{

  undefined4 uVar1;

  longlong lVar2;

  undefined8 uVar3;

  undefined8 local_48;

  undefined8 uStack_40;

  longlong local_38;

  undefined8 local_30;

  undefined1 local_28 [32];

  

  local_38 = 8;

  local_30 = 0xf;

  local_48 = 0x6e6f634974697845;

  uStack_40 = 0;

  lVar2 = FUN_1400c9c30(0,0,0x117,4,0x25,0x12,0x800);

  *(undefined4 *)(lVar2 + 0x54) = 3;

  *(undefined4 *)(lVar2 + 0x50) = 0x3f800000;

  if (local_38 == 0) {

    uVar1 = 0xffffffff;

  }

  else {

    uVar3 = FUN_1400279c0(local_28,&local_48);

    uVar1 = FUN_14006fe60(uVar3);

  }

  *(undefined4 *)(lVar2 + 0x2c) = uVar1;

  *(uint *)(lVar2 + 0x30) = *(uint *)(lVar2 + 0x30) | 4;

  FUN_140027900(&local_48);

  return lVar2;

}




