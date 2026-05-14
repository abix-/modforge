// Address: 0x14015d600
// Ghidra name: FUN_14015d600
// ============ 0x14015d600 FUN_14015d600 (size=412) ============


void FUN_14015d600(longlong param_1)



{

  bool bVar1;

  char cVar2;

  undefined4 *puVar3;

  undefined4 *puVar4;

  undefined4 *puVar5;

  undefined4 local_28 [2];

  longlong local_20;

  

  puVar5 = local_28;

  local_20 = 0;

  FUN_14015cde0();

  FUN_14017caa0(DAT_1403fc128);

  if ((*(int *)(param_1 + 0x50) == DAT_1403fc148) || (*(int *)(param_1 + 0x50) == DAT_1403fc14c)) {

    bVar1 = true;

  }

  else {

    bVar1 = false;

  }

  FUN_14017cae0(DAT_1403fc128);

  cVar2 = FUN_140138fc0(param_1 + 0x90,0,1);

  if (cVar2 == '\0') {

LAB_14015d735:

    puVar4 = puVar5;

    FUN_14015d3e0(param_1);

    if (cVar2 == '\0') goto LAB_14015d780;

  }

  else {

    puVar4 = *(undefined4 **)(param_1 + 0xd0);

    *(undefined1 **)(param_1 + 0x28) = &LAB_140160080;

    *(code **)(param_1 + 0x20) = FUN_140018e60;

    *(code **)(param_1 + 0x38) = FUN_140160090;

    *(code **)(param_1 + 0x40) = _guard_check_icall;

    *(code **)(param_1 + 0x18) = FUN_1401600c0;

    *(code **)(param_1 + 0x30) = FUN_1401600c0;

    for (; puVar4 != (undefined4 *)0x0; puVar4 = *(undefined4 **)(puVar4 + 0xe)) {

      if (((!bVar1) || (*(char *)(puVar4 + 8) == '\0')) &&

         (puVar3 = (undefined4 *)FUN_1401841f0(0x10), puVar3 != (undefined4 *)0x0)) {

        *puVar3 = 0x1101;

        puVar3[1] = *puVar4;

        *(undefined8 *)(puVar3 + 2) = 0;

        *(undefined4 **)(puVar5 + 2) = puVar3;

        puVar5 = puVar3;

      }

    }

    puVar4 = (undefined4 *)FUN_1401841f0(0x10);

    if (puVar4 == (undefined4 *)0x0) goto LAB_14015d735;

    *puVar4 = 0x1101;

    puVar4[1] = *(undefined4 *)(param_1 + 0x50);

    *(undefined8 *)(puVar4 + 2) = 0;

    *(undefined4 **)(puVar5 + 2) = puVar4;

    FUN_14015d3e0(param_1);

  }

  if (local_20 != 0) {

    FUN_14017cab0(DAT_1403fc128);

    *(longlong *)(DAT_1403fc160 + 2) = local_20;

    DAT_1403fc160 = puVar4;

    FUN_14017cae0(DAT_1403fc128);

  }

  FUN_14015fe40(param_1);

LAB_14015d780:

  FUN_14015fe40(param_1);

  return;

}




