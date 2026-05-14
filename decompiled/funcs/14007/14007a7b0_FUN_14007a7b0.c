// Address: 0x14007a7b0
// Ghidra name: FUN_14007a7b0
// ============ 0x14007a7b0 FUN_14007a7b0 (size=403) ============


void FUN_14007a7b0(undefined8 *param_1,int param_2,int param_3,int param_4,int param_5,byte *param_6

                  )



{

  byte bVar1;

  byte bVar2;

  int iVar3;

  undefined8 uVar4;

  byte *pbVar5;

  undefined8 uVar6;

  longlong lVar7;

  byte local_res18 [8];

  char acStackX_20 [8];

  

  local_res18[0] = 0xff;

  local_res18[1] = 0;

  local_res18[2] = 0xff;

  if (param_4 < 0) {

    (*(code *)*param_1)(param_1[1],param_6 + (param_3 + -1),1);

  }

  pbVar5 = param_6;

  if (param_3 == 1) {

    uVar6 = 1;

LAB_14007a910:

    uVar4 = param_1[1];

LAB_14007a914:

    (*(code *)*param_1)(uVar4,pbVar5,uVar6);

  }

  else {

    if (param_3 == 2) {

      uVar4 = param_1[1];

      if (param_5 == 0) {

        uVar6 = 1;

      }

      else {

        local_res18[2] = *param_6;

        uVar6 = 3;

        local_res18[1] = local_res18[2];

        local_res18[0] = local_res18[2];

        pbVar5 = local_res18;

      }

      goto LAB_14007a914;

    }

    if (param_3 == 3) {

LAB_14007a8aa:

      uVar6 = 3;

      local_res18[2] = param_6[(longlong)param_2 + 1];

      local_res18[1] = param_6[1];

      local_res18[0] = param_6[1 - param_2];

      pbVar5 = local_res18;

      goto LAB_14007a910;

    }

    if (param_3 == 4) {

      if (param_4 == 0) {

        bVar1 = param_6[3];

        lVar7 = 0;

        do {

          bVar2 = local_res18[lVar7];

          iVar3 = ((uint)(local_res18 + lVar7)[(longlong)param_6 - (longlong)local_res18] -

                  (uint)bVar2) * (uint)bVar1;

          acStackX_20[lVar7] =

               (((char)(iVar3 / 0xff) + (char)(iVar3 >> 0x1f)) -

               (char)((longlong)iVar3 * 0x80808081 >> 0x3f)) + bVar2;

          lVar7 = lVar7 + 1;

        } while (lVar7 < 3);

        param_6 = local_res18;

        uVar6 = 3;

        local_res18[0] = acStackX_20[1 - param_2];

        local_res18[2] = acStackX_20[(longlong)param_2 + 1];

        local_res18[1] = acStackX_20[1];

        goto LAB_14007a925;

      }

      goto LAB_14007a8aa;

    }

  }

  if (param_4 < 1) {

    return;

  }

  param_6 = param_6 + (param_3 + -1);

  uVar6 = 1;

LAB_14007a925:

  (*(code *)*param_1)(param_1[1],param_6,uVar6);

  return;

}




