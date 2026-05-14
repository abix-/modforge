// Address: 0x1400e45a0
// Ghidra name: FUN_1400e45a0
// ============ 0x1400e45a0 FUN_1400e45a0 (size=378) ============


undefined8 FUN_1400e45a0(undefined8 param_1)



{

  byte bVar1;

  undefined *puVar2;

  int iVar3;

  longlong lVar4;

  byte *pbVar5;

  undefined8 uVar6;

  uint uVar7;

  char *pcVar8;

  bool bVar9;

  byte local_a0 [128];

  byte *local_20;

  byte *local_18;

  byte *local_10;

  

  lVar4 = FUN_1402ce0f8(param_1,&DAT_14039be7c);

  puVar2 = PTR_LAB_1403dade0;

  if (lVar4 == 0) {

    uVar6 = 0;

  }

  else {

    local_10 = local_a0;

    iVar3 = (*(code *)PTR_LAB_1403dade0)(lVar4,local_a0,0x80);

    bVar9 = iVar3 != 0;

    if (bVar9) {

      pbVar5 = local_a0;

      local_18 = local_a0 + iVar3;

      local_20 = pbVar5;

    }

    else {

      pbVar5 = local_18 + -1;

      local_20 = pbVar5;

      *pbVar5 = 0;

    }

    pcVar8 = "#?RADIANCE\n";

    local_20 = pbVar5;

    do {

      if (pbVar5 < local_18) {

        bVar1 = *pbVar5;

        pbVar5 = pbVar5 + 1;

        local_20 = pbVar5;

        uVar7 = (uint)bVar1;

      }

      else {

        uVar7 = 0;

        if (bVar9) {

          iVar3 = (*(code *)puVar2)(lVar4,local_a0,0x80);

          if (iVar3 == 0) {

            local_20 = local_18 + -1;

            bVar9 = false;

            *local_20 = 0;

            bVar1 = *local_20;

            pbVar5 = local_20 + 1;

            local_20 = pbVar5;

            uVar7 = (uint)bVar1;

          }

          else {

            local_18 = local_a0 + iVar3;

            pbVar5 = local_a0 + 1;

            local_20 = pbVar5;

            uVar7 = (uint)local_a0[0];

          }

        }

      }

      uVar6 = 0;

    } while ((uVar7 == (int)*pcVar8) && (pcVar8 = pcVar8 + 1, uVar6 = 1, *pcVar8 != '\0'));

    FUN_1402ce288(lVar4);

  }

  return uVar6;

}




