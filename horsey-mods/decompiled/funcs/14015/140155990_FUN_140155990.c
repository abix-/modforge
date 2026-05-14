// Address: 0x140155990
// Ghidra name: FUN_140155990
// ============ 0x140155990 FUN_140155990 (size=692) ============


undefined8 FUN_140155990(int *param_1,undefined8 param_2,byte *param_3)



{

  int iVar1;

  undefined8 uVar2;

  undefined4 *puVar3;

  char cVar4;

  int iVar5;

  uint uVar6;

  uint uVar7;

  undefined4 uVar8;

  longlong lVar9;

  undefined1 local_res8 [16];

  undefined1 local_res18 [8];

  undefined1 local_res20 [8];

  undefined1 local_38 [4];

  undefined4 local_34 [3];

  

  if ((*(int *)(param_3 + 4) == *param_1) && (iVar5 = FUN_140146870(param_3), iVar5 == param_1[6]))

  {

    uVar7 = *(uint *)(param_3 + 4);

    if (uVar7 == 0) {

LAB_1401559ed:

      if (((uVar7 & 0xf000000) + 0xfb000000 & 0xfeffffff) != 0) {

LAB_140155a1c:

        if (uVar7 != 0) goto LAB_140155a20;

        goto LAB_140155a32;

      }

LAB_1401559f9:

      uVar6 = uVar7 & 0xf00000;

      if ((((uVar6 != 0x300000) && (uVar6 != 0x400000)) && (uVar6 != 0x700000)) &&

         (uVar6 != 0x800000)) goto LAB_140155a1c;

LAB_140155a7d:

      cVar4 = FUN_140148960(param_3);

      if (cVar4 != '\0') goto LAB_140155a91;

    }

    else {

      if ((uVar7 & 0xf0000000) == 0x10000000) {

        if ((uVar7 & 0xf000000) != 0x4000000) goto LAB_1401559ed;

        goto LAB_1401559f9;

      }

LAB_140155a20:

      if ((uVar7 & 0xf0000000) == 0x10000000) {

LAB_140155a32:

        uVar7 = *(uint *)(param_3 + 4) & 0xf000000;

        if (((uVar7 == 0x7000000) || ((uVar7 + 0xf8000000 & 0xfcffffff) == 0)) &&

           (((uVar7 = *(uint *)(param_3 + 4) & 0xf00000, uVar7 == 0x300000 ||

             ((uVar7 == 0x200000 || (uVar7 == 0x600000)))) || (uVar7 == 0x500000))))

        goto LAB_140155a7d;

      }

    }

    if ((*param_3 & 2) == 0) {

      FUN_140156430(param_1,param_2,*(undefined8 *)(param_3 + 0x18),*(undefined4 *)(param_3 + 0x10))

      ;

    }

    else {

      cVar4 = FUN_140146f20(param_3);

      if (cVar4 != '\0') {

        FUN_140156430(param_1,param_2,*(undefined8 *)(param_3 + 0x18),

                      *(undefined4 *)(param_3 + 0x10));

        FUN_1401489e0(param_3);

      }

    }

  }

  else {

LAB_140155a91:

    iVar5 = param_1[6];

    uVar2 = *(undefined8 *)(param_1 + 0x36);

    iVar1 = *param_1;

    uVar8 = FUN_140146bc0(param_3);

    lVar9 = FUN_140145220(param_3,iVar1,uVar2,iVar5,uVar8);

    if (lVar9 == 0) {

      return 0;

    }

    FUN_140156430(param_1,0,*(undefined8 *)(lVar9 + 0x18),*(undefined4 *)(lVar9 + 0x10));

    FUN_140146010(lVar9);

  }

  if ((*param_1 == *(int *)(param_3 + 4)) &&

     (puVar3 = *(undefined4 **)(param_3 + 0x48), puVar3 != (undefined4 *)0x0)) {

    lVar9 = FUN_14017a030(*puVar3);

    if ((lVar9 == 0) ||

       ((cVar4 = FUN_14017c2a0(lVar9,*(undefined8 *)(puVar3 + 2),0,*puVar3), cVar4 == '\0' ||

        (cVar4 = FUN_140155130(param_1,lVar9), cVar4 == '\0')))) {

      FUN_14017a0f0(lVar9);

      return 0;

    }

    FUN_14017a0f0(lVar9);

  }

  FUN_1401467d0(param_3,local_res20,local_res18,local_res8);

  FUN_1401550f0(param_1,local_res20[0],local_res18[0],local_res8[0]);

  FUN_140146570(param_3,local_38);

  FUN_140154f80(param_1,local_38[0]);

  cVar4 = FUN_140148960(param_3);

  if (cVar4 != '\0') {

    FUN_140154fa0(param_1,1);

    return 1;

  }

  FUN_1401465d0(param_3,local_34);

  FUN_140154fa0(param_1,local_34[0]);

  return 1;

}




