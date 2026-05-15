// Address: 0x1400e4720
// Ghidra name: FUN_1400e4720
// ============ 0x1400e4720 FUN_1400e4720 (size=311) ============


undefined8 FUN_1400e4720(undefined8 param_1)



{

  byte bVar1;

  undefined *puVar2;

  int iVar3;

  byte *pbVar4;

  char *pcVar5;

  uint uVar6;

  bool bVar7;

  byte local_a0 [128];

  byte *local_20;

  byte *local_18;

  byte *local_10;

  

  puVar2 = PTR_LAB_1403dade0;

  local_10 = local_a0;

  iVar3 = (*(code *)PTR_LAB_1403dade0)(PTR_LAB_1403dadf0,local_a0,0x80);

  bVar7 = iVar3 != 0;

  if (bVar7) {

    pbVar4 = local_a0;

    local_18 = local_a0 + iVar3;

    local_20 = pbVar4;

  }

  else {

    pbVar4 = local_18 + -1;

    local_20 = pbVar4;

    *pbVar4 = 0;

  }

  pcVar5 = "#?RADIANCE\n";

  local_20 = pbVar4;

  while( true ) {

    if (pbVar4 < local_18) {

      bVar1 = *pbVar4;

      pbVar4 = pbVar4 + 1;

      local_20 = pbVar4;

      uVar6 = (uint)bVar1;

    }

    else {

      uVar6 = 0;

      if (bVar7) {

        iVar3 = (*(code *)puVar2)(param_1,local_a0,0x80);

        if (iVar3 == 0) {

          local_20 = local_18 + -1;

          bVar7 = false;

          *local_20 = 0;

          bVar1 = *local_20;

          pbVar4 = local_20 + 1;

          local_20 = pbVar4;

          uVar6 = (uint)bVar1;

        }

        else {

          local_18 = local_a0 + iVar3;

          pbVar4 = local_a0 + 1;

          local_20 = pbVar4;

          uVar6 = (uint)local_a0[0];

        }

      }

    }

    if (uVar6 != (int)*pcVar5) break;

    pcVar5 = pcVar5 + 1;

    if (*pcVar5 == '\0') {

      return 1;

    }

  }

  return 0;

}




