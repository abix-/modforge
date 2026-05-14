// Address: 0x140028cc0
// Ghidra name: FUN_140028cc0
// ============ 0x140028cc0 FUN_140028cc0 (size=1098) ============


byte * FUN_140028cc0(byte *param_1,undefined8 *param_2,char param_3,byte *param_4,int param_5,

                    int param_6)



{

  ulonglong uVar1;

  bool bVar2;

  int iVar3;

  int iVar4;

  byte *pbVar5;

  longlong lVar6;

  undefined8 *puVar7;

  int iVar8;

  byte *pbVar9;

  byte bVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  undefined4 local_res18 [2];

  

  FUN_140027f50(param_2,&DAT_14039bcb9,0);

  iVar3 = param_6;

  if (param_3 == '\0') {

    while ((param_1 != (byte *)0x0 && (*param_1 != 0))) {

      if (param_4 == (byte *)0x0) {

        FID_conflict__assert(L"tag",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21c);

      }

      pbVar5 = param_1;

      pbVar9 = param_4;

      if (*param_1 == 0) {

        FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

      }

      else {

        do {

          if ((*pbVar9 == 0) || (*pbVar5 != *pbVar9)) break;

          pbVar5 = pbVar5 + 1;

          pbVar9 = pbVar9 + 1;

        } while (*pbVar5 != 0);

        if (*pbVar9 == 0) goto LAB_140028d71;

      }

      local_res18[0] = 0;

      if (iVar3 == 1) {

        iVar4 = *(int *)(&DAT_140399fb0 + (ulonglong)*param_1 * 4);

        param_5 = iVar4;

        if ((iVar4 < 0) || (4 < iVar4)) {

          FID_conflict__assert(L"*length >= 0 && *length < 5",L"C:\\dev\\tinyxml\\tinyxml.h",0x14e);

        }

        if (iVar4 == 1) goto LAB_140029076;

        if (iVar4 == 0) {

          param_1 = (byte *)0x0;

        }

        else {

          iVar8 = 0;

          if (*param_1 != 0) {

            pbVar5 = param_1;

            do {

              if (iVar4 <= iVar8) break;

              iVar8 = iVar8 + 1;

              pbVar5[(longlong)local_res18 - (longlong)param_1] = *pbVar5;

              pbVar5 = pbVar5 + 1;

            } while (*pbVar5 != 0);

          }

          param_1 = param_1 + iVar4;

        }

      }

      else {

        iVar4 = 1;

        param_5 = 1;

LAB_140029076:

        if (*param_1 == 0x26) {

          param_1 = (byte *)FUN_1400289d0(param_1,local_res18,&param_5,iVar3);

          iVar4 = param_5;

        }

        else {

          local_res18[0] = CONCAT31(local_res18[0]._1_3_,*param_1);

          param_1 = param_1 + 1;

        }

      }

      lVar6 = param_2[2];

      uVar12 = (ulonglong)iVar4;

      if ((ulonglong)(param_2[3] - lVar6) < uVar12) {

        FUN_140027c80(param_2);

      }

      else {

        param_2[2] = lVar6 + uVar12;

        puVar7 = param_2;

        if (0xf < (ulonglong)param_2[3]) {

          puVar7 = (undefined8 *)*param_2;

        }

        FUN_1402f8e20((longlong)puVar7 + lVar6,local_res18,uVar12);

        *(undefined1 *)((longlong)puVar7 + lVar6 + uVar12) = 0;

      }

    }

  }

  else {

    bVar2 = false;

    param_1 = (byte *)FUN_140028820(param_1);

    while ((param_1 != (byte *)0x0 && (*param_1 != 0))) {

      if (param_4 == (byte *)0x0) {

        FID_conflict__assert(L"tag",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21c);

      }

      pbVar5 = param_1;

      pbVar9 = param_4;

      if (*param_1 == 0) {

        FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

      }

      else {

        do {

          if ((*pbVar9 == 0) || (*pbVar5 != *pbVar9)) break;

          pbVar5 = pbVar5 + 1;

          pbVar9 = pbVar9 + 1;

        } while (*pbVar5 != 0);

        if (*pbVar9 == 0) {

LAB_140028d71:

          if (*param_1 == 0) {

            return param_1;

          }

          lVar6 = -1;

          do {

            lVar6 = lVar6 + 1;

          } while (param_4[lVar6] != 0);

          return param_1 + lVar6;

        }

      }

      bVar10 = *param_1;

      if (((bVar10 == 0xd) || (bVar10 == 10)) || (iVar4 = isspace((uint)bVar10), iVar4 != 0)) {

        param_1 = param_1 + 1;

        bVar2 = true;

      }

      else {

        if (bVar2) {

          uVar12 = param_2[2];

          if (uVar12 < (ulonglong)param_2[3]) {

            param_2[2] = uVar12 + 1;

            puVar7 = param_2;

            if (0xf < (ulonglong)param_2[3]) {

              puVar7 = (undefined8 *)*param_2;

            }

            *(undefined2 *)((longlong)puVar7 + uVar12) = 0x20;

          }

          else {

            FUN_1400280d0(param_2);

          }

        }

        bVar2 = false;

        local_res18[0] = 0;

        if (iVar3 == 1) {

          iVar4 = *(int *)(&DAT_140399fb0 + (ulonglong)*param_1 * 4);

          param_5 = iVar4;

          if ((iVar4 < 0) || (4 < iVar4)) {

            FID_conflict__assert

                      (L"*length >= 0 && *length < 5",L"C:\\dev\\tinyxml\\tinyxml.h",0x14e);

          }

          if (iVar4 == 1) goto LAB_140028e90;

          bVar10 = 0;

          if (iVar4 == 0) {

            param_1 = (byte *)0x0;

          }

          else {

            iVar8 = 0;

            if (*param_1 != 0) {

              pbVar5 = param_1;

              do {

                if (iVar4 <= iVar8) break;

                iVar8 = iVar8 + 1;

                pbVar5[(longlong)local_res18 - (longlong)param_1] = *pbVar5;

                pbVar5 = pbVar5 + 1;

              } while (*pbVar5 != 0);

              bVar10 = (byte)local_res18[0];

            }

            param_1 = param_1 + iVar4;

          }

        }

        else {

          iVar4 = 1;

          param_5 = 1;

LAB_140028e90:

          bVar10 = *param_1;

          if (bVar10 == 0x26) {

            param_1 = (byte *)FUN_1400289d0(param_1,local_res18,&param_5,iVar3);

            iVar4 = param_5;

            bVar10 = (byte)local_res18[0];

          }

          else {

            local_res18[0] = CONCAT31(local_res18[0]._1_3_,bVar10);

            param_1 = param_1 + 1;

          }

        }

        uVar12 = param_2[2];

        uVar1 = param_2[3];

        if (iVar4 == 1) {

          if (uVar12 < uVar1) {

            param_2[2] = uVar12 + 1;

            puVar7 = param_2;

            if (0xf < uVar1) {

              puVar7 = (undefined8 *)*param_2;

            }

            *(byte *)((longlong)puVar7 + uVar12) = bVar10;

            *(undefined1 *)((longlong)puVar7 + uVar12 + 1) = 0;

          }

          else {

            FUN_1400280d0(param_2);

          }

        }

        else {

          uVar11 = (ulonglong)iVar4;

          if (uVar1 - uVar12 < uVar11) {

            FUN_140027c80(param_2);

          }

          else {

            param_2[2] = uVar12 + uVar11;

            puVar7 = param_2;

            if (0xf < uVar1) {

              puVar7 = (undefined8 *)*param_2;

            }

            FUN_1402f8e20((longlong)puVar7 + uVar12,local_res18,uVar11);

            *(undefined1 *)((longlong)puVar7 + uVar12 + uVar11) = 0;

          }

        }

      }

    }

  }

  return param_1;

}




