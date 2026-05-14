// Address: 0x140175ef0
// Ghidra name: FUN_140175ef0
// ============ 0x140175ef0 FUN_140175ef0 (size=281) ============


void FUN_140175ef0(longlong *param_1,uint *param_2)



{

  undefined4 *puVar1;

  int iVar2;

  uint uVar3;

  char *pcVar4;

  longlong lVar5;

  int local_res18 [2];

  undefined4 local_res20;

  undefined2 local_res24 [2];

  

  local_res18[0] = 0;

  pcVar4 = (char *)FUN_140142960("SDL_JOYSTICK_HAPTIC_AXES");

  if (pcVar4 != (char *)0x0) {

    iVar2 = FUN_14012ef30(pcVar4,"0x%hx/0x%hx/%hu%n",&local_res20,(longlong)&local_res20 + 2,

                          local_res24,local_res18);

    while (iVar2 == 3) {

      pcVar4 = pcVar4 + local_res18[0];

      local_res18[0] = 0;

      uVar3 = *param_2 & 0x80000007;

      if ((int)uVar3 < 0) {

        uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;

      }

      if (uVar3 == 0) {

        lVar5 = FUN_140184230(*param_1,(longlong)(int)(*param_2 + 8) * 6);

        if (lVar5 == 0) {

          return;

        }

        *param_1 = lVar5;

      }

      puVar1 = (undefined4 *)(*param_1 + (longlong)(int)*param_2 * 6);

      *puVar1 = local_res20;

      *(undefined2 *)(puVar1 + 1) = local_res24[0];

      *param_2 = *param_2 + 1;

      if (*pcVar4 == ',') {

        pcVar4 = pcVar4 + 1;

      }

      iVar2 = FUN_14012ef30(pcVar4,"0x%hx/0x%hx/%hu%n",&local_res20,(longlong)&local_res20 + 2,

                            local_res24,local_res18);

    }

  }

  return;

}




