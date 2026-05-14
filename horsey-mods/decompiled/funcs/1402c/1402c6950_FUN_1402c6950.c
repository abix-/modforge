// Address: 0x1402c6950
// Ghidra name: FUN_1402c6950
// ============ 0x1402c6950 FUN_1402c6950 (size=134) ============


ulonglong FUN_1402c6950(undefined8 *param_1,uint param_2)



{

  longlong *plVar1;

  uint *puVar2;

  uint uVar3;

  byte *pbVar4;

  int iVar5;

  uint *in_RAX;

  undefined4 extraout_var;

  uint *puVar6;

  undefined1 auVar7 [16];

  uint local_res10 [2];

  

  local_res10[0] = param_2;

  if (param_2 != 0) {

    plVar1 = (longlong *)*param_1;

    puVar2 = (uint *)*plVar1;

    do {

      uVar3 = 0x1f;

      if (local_res10[0] != 0) {

        for (; local_res10[0] >> uVar3 == 0; uVar3 = uVar3 - 1) {

        }

      }

      puVar6 = puVar2;

      if ((uVar3 == 0) ||

         (puVar6 = (uint *)((longlong)puVar2 + (ulonglong)uVar3),

         auVar7._0_4_ = *puVar6 ^ *(uint *)(param_1 + 2),

         auVar7._4_4_ = puVar6[1] ^ *(uint *)((longlong)param_1 + 0x14),

         auVar7._8_4_ = puVar6[2] ^ *(uint *)(param_1 + 3),

         auVar7._12_4_ = puVar6[3] ^ *(uint *)((longlong)param_1 + 0x1c),

         auVar7 == (undefined1  [16])0x0)) {

        iVar5 = memcmp(puVar6 + 4,(void *)param_1[4],param_1[5] - 0x10);

        if (iVar5 == 0) {

          *plVar1 = (longlong)puVar6;

          return CONCAT71((int7)(CONCAT44(extraout_var,iVar5) >> 8),1);

        }

      }

      in_RAX = local_res10;

      pbVar4 = (byte *)((longlong)in_RAX + ((longlong)(int)uVar3 >> 3));

      *pbVar4 = *pbVar4 & ~('\x01' << (uVar3 & 7));

    } while (local_res10[0] != 0);

  }

  return (ulonglong)in_RAX & 0xffffffffffffff00;

}




