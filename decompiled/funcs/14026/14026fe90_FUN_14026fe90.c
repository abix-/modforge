// Address: 0x14026fe90
// Ghidra name: FUN_14026fe90
// ============ 0x14026fe90 FUN_14026fe90 (size=146) ============


void FUN_14026fe90(longlong param_1)



{

  longlong lVar1;

  uint uVar2;

  undefined2 local_38;

  undefined1 local_36;

  undefined1 local_35;

  undefined1 local_34;

  undefined4 local_33;

  char local_2f;

  undefined4 local_2e;

  undefined4 local_2a;

  undefined4 local_26;

  undefined4 local_22;

  undefined8 local_1e;

  undefined1 local_16;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  local_38 = 0xff01;

  local_35 = 0xff;

  local_33 = 0;

  local_36 = *(char *)(lVar1 + 0x19) != '\0';

  local_34 = *(undefined1 *)(lVar1 + 0x18);

  local_2e = 0x1027ff;

  local_2a = 0x1027ff32;

  local_26 = 0x27ff3200;

  local_22 = 0xff320010;

  local_1e = 0x32001027;

  local_16 = 0;

  uVar2 = *(uint *)(lVar1 + 0x14) & 0x80000003;

  if ((int)uVar2 < 0) {

    uVar2 = (uVar2 - 1 | 0xfffffffc) + 1;

  }

  local_2f = '\x01' << ((char)uVar2 + 1U & 0x1f);

  FUN_14026e170(param_1,*(undefined8 *)(lVar1 + 8),&local_38,0x23);

  return;

}




