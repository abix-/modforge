// Address: 0x140032320
// Ghidra name: FUN_140032320
// ============ 0x140032320 FUN_140032320 (size=639) ============


void FUN_140032320(longlong param_1)



{

  longlong *plVar1;

  int iVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  char *_Str;

  uint uVar7;

  char **ppcVar8;

  undefined1 *puVar9;

  longlong local_268 [4];

  char *local_248;

  char *local_240 [4];

  char *local_220;

  char *local_218;

  char *local_210;

  char *local_208;

  char *local_200;

  char *local_1f8;

  undefined4 *local_1f0;

  undefined1 local_1e8 [480];

  

  *(undefined4 *)(param_1 + 0x690) = 0;

  lVar3 = param_1 + 0x2ba;

  lVar5 = 0xf0;

  do {

    *(undefined4 *)(lVar3 + -2) = 0;

    lVar3 = lVar3 + 4;

    lVar5 = lVar5 + -1;

  } while (lVar5 != 0);

  _Str = "crazy horse";

  local_248 = "crazy horse";

  local_240[0] = "human";

  local_240[1] = "giraffe";

  local_240[2] = "rabbit";

  local_240[3] = "impala";

  local_220 = "freak";

  local_218 = "freak";

  local_210 = "freak";

  local_208 = "crazy horse";

  local_200 = "centipede";

  local_1f8 = "alligator";

  local_1f0 = &DAT_140303b54;

  plVar1 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar1 = DAT_1403d9530;

  }

  if (DAT_1403d9540 == 9) {

    lVar3 = *plVar1 + -0x656b6361686f6942;

    if (lVar3 == 0) {

      lVar3 = (ulonglong)*(byte *)(plVar1 + 1) - 0x72;

    }

    if (lVar3 == 0) goto LAB_140032470;

  }

  plVar1 = (longlong *)&DAT_1403d9530;

  if (0xf < DAT_1403d9548) {

    plVar1 = DAT_1403d9530;

  }

  if (DAT_1403d9540 != 6) {

    return;

  }

  iVar2 = (int)*plVar1 + -0x74696c47;

  if (iVar2 == 0) {

    iVar2 = *(ushort *)((longlong)plVar1 + 4) - 0x6863;

  }

  if (iVar2 != 0) {

    return;

  }

LAB_140032470:

  uVar7 = 0;

  ppcVar8 = &local_248;

  while( true ) {

    local_268[0] = 0;

    local_268[1] = 0;

    local_268[2] = 0;

    local_268[3] = 0;

    strlen(_Str);

    FUN_140027e30(local_268,_Str);

    FUN_1400a2ed0(local_1e8,local_268);

    if (0xf < (ulonglong)local_268[3]) {

      if ((0xfff < local_268[3] + 1U) &&

         (0x1f < (local_268[0] - *(longlong *)(local_268[0] + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

        _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

      }

      FUN_1402c7088();

    }

    puVar9 = local_1e8;

    lVar3 = 2;

    do {

      lVar6 = 0;

      lVar5 = 0x2b8;

      do {

        if ((puVar9[lVar6] != -1) &&

           (lVar4 = (char)puVar9[lVar6] + lVar5, *(char *)(lVar4 + param_1) == '\0')) {

          *(undefined1 *)(lVar4 + param_1) = 1;

        }

        lVar6 = lVar6 + 1;

        lVar5 = lVar5 + 4;

      } while (lVar5 < 0x678);

      puVar9 = puVar9 + 0xf0;

      lVar3 = lVar3 + -1;

    } while (lVar3 != 0);

    uVar7 = uVar7 + 1;

    ppcVar8 = ppcVar8 + 1;

    if (0xb < uVar7) break;

    _Str = *ppcVar8;

  }

  FUN_140032610(param_1);

  return;

}




