// Address: 0x140163a10
// Ghidra name: FUN_140163a10
// ============ 0x140163a10 FUN_140163a10 (size=136) ============


void FUN_140163a10(undefined8 *param_1)



{

  undefined8 uVar1;

  code *pcVar2;

  undefined8 uVar3;

  char cVar4;

  undefined4 uVar5;

  int iVar6;

  

  uVar1 = param_1[0xc];

  pcVar2 = (code *)param_1[0xb];

  FUN_1401800c0(param_1[8]);

  uVar3 = FUN_14017ffb0();

  *param_1 = uVar3;

  FUN_14017cea0(param_1[10]);

  uVar5 = (*pcVar2)(uVar1);

  *(undefined4 *)(param_1 + 2) = uVar5;

  FUN_1401631f0();

  cVar4 = FUN_140138fc0((longlong)param_1 + 0x14,1,3);

  if (cVar4 == '\0') {

    iVar6 = FUN_140138fe0((longlong)param_1 + 0x14);

    if (iVar6 == 2) {

      FUN_1401841e0(param_1[8]);

      FUN_1401841e0(param_1);

    }

  }

  return;

}




