// Address: 0x1402df9d0
// Ghidra name: FUN_1402df9d0
// ============ 0x1402df9d0 FUN_1402df9d0 (size=161) ============


bool FUN_1402df9d0(longlong param_1)



{

  longlong *plVar1;

  uint *puVar2;

  int iVar3;

  undefined4 *puVar4;

  bool bVar5;

  char local_res8 [8];

  uint local_res10 [2];

  longlong local_28;

  undefined8 local_20;

  undefined8 local_18;

  char *local_10;

  

  local_res10[0] = 0;

  local_28 = param_1 + 8;

  local_20 = *(undefined8 *)(param_1 + 0x40);

  local_10 = local_res8;

  local_18 = 0;

  local_res8[0] = '\x01';

  iVar3 = parse_floating_point<>(*(undefined8 *)(param_1 + 0x78),&local_28,local_res10);

  if ((local_res8[0] == '\0') || (iVar3 == 1)) {

    bVar5 = false;

  }

  else if (*(char *)(param_1 + 0x3a) == '\0') {

    plVar1 = *(longlong **)(param_1 + 0x80);

    *(longlong **)(param_1 + 0x80) = plVar1 + 1;

    puVar2 = (uint *)*plVar1;

    bVar5 = puVar2 != (uint *)0x0;

    if (bVar5) {

      *puVar2 = local_res10[0];

    }

    else {

      puVar4 = (undefined4 *)FUN_1402e68b0();

      *puVar4 = 0x16;

      FUN_1402cd454();

    }

  }

  else {

    bVar5 = true;

  }

  return bVar5;

}




