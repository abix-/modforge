// Address: 0x140047170
// Ghidra name: FUN_140047170
// ============ 0x140047170 FUN_140047170 (size=105) ============


undefined8 FUN_140047170(undefined1 *param_1)



{

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  local_28 = *(undefined4 *)(param_1 + 8);

  uStack_24 = *(undefined4 *)(param_1 + 0xc);

  uStack_20 = *(undefined4 *)(param_1 + 0x10);

  uStack_1c = *(undefined4 *)(param_1 + 0x14);

  local_18 = *(undefined4 *)(param_1 + 0x18);

  uStack_14 = *(undefined4 *)(param_1 + 0x1c);

  uStack_10 = *(undefined4 *)(param_1 + 0x20);

  uStack_c = *(undefined4 *)(param_1 + 0x24);

  *(undefined8 *)(param_1 + 0x18) = 0;

  *(undefined8 *)(param_1 + 0x20) = 0xf;

  param_1[8] = 0;

  (**(code **)(param_1 + 0x28))(&local_28,*param_1);

  FUN_1402c6a5c();

  FUN_140027900(param_1 + 8);

  FUN_1402c7088(param_1,0x30);

  return 0;

}




