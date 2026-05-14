// Address: 0x1401702f0
// Ghidra name: FUN_1401702f0
// ============ 0x1401702f0 FUN_1401702f0 (size=114) ============


void FUN_1401702f0(longlong param_1,longlong param_2)



{

  undefined8 *puVar1;

  char cVar2;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  

  puVar1 = *(undefined8 **)(param_1 + 0x48);

  if (puVar1 == (undefined8 *)0x0) {

    local_38 = 0;

    uStack_30 = 0;

    local_18 = 0;

    local_28 = 0;

    uStack_20 = 0;

  }

  else {

    local_38 = *puVar1;

    uStack_30 = puVar1[1];

    local_28 = puVar1[2];

    uStack_20 = puVar1[3];

    local_18 = puVar1[4];

  }

  *(longlong *)(param_1 + 0x48) = param_2;

  cVar2 = FUN_140169c20(&local_38);

  if (cVar2 != '\0') {

    FUN_14021a690(param_1,0x156,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc));

    return;

  }

  return;

}




