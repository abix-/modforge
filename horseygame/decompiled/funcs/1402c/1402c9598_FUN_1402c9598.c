// Address: 0x1402c9598
// Ghidra name: FUN_1402c9598
// ============ 0x1402c9598 FUN_1402c9598 (size=535) ============


undefined8

FUN_1402c9598(PEXCEPTION_RECORD param_1,PVOID param_2,undefined8 param_3,longlong *param_4)



{

  uint uVar1;

  longlong lVar2;

  uint *puVar3;

  int iVar4;

  BOOL BVar5;

  uint uVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  uint uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  PEXCEPTION_RECORD local_38;

  undefined8 local_30;

  

  __except_validate_context_record(param_3);

  lVar2 = param_4[1];

  puVar3 = (uint *)param_4[7];

  uVar11 = *param_4 - lVar2;

  uVar9 = *(uint *)(param_4 + 9);

  local_38 = param_1;

  local_30 = param_3;

  if ((param_1->ExceptionFlags & 0x66) == 0) {

    for (; uVar9 < *puVar3; uVar9 = uVar9 + 1) {

      uVar8 = (ulonglong)uVar9;

      if (((puVar3[uVar8 * 4 + 1] <= uVar11) && (uVar11 < puVar3[uVar8 * 4 + 2])) &&

         (puVar3[uVar8 * 4 + 4] != 0)) {

        if (puVar3[uVar8 * 4 + 3] != 1) {

          iVar4 = (*(code *)((ulonglong)puVar3[uVar8 * 4 + 3] + lVar2))(&local_38,param_2);

          if (iVar4 < 0) {

            return 0;

          }

          if (iVar4 < 1) goto LAB_1402c96bf;

        }

        if (((param_1->ExceptionCode == 0xe06d7363) && (PTR_FUN_140387418 != (undefined *)0x0)) &&

           (BVar5 = _IsNonwritableInCurrentImage((PBYTE)&PTR_FUN_140387418), BVar5 != 0)) {

          (*(code *)PTR_FUN_140387418)(param_1,1);

        }

        FUN_1402ccbe0((ulonglong)puVar3[((ulonglong)uVar9 + 1) * 4] + lVar2,param_2,1);

        RtlUnwindEx(param_2,(PVOID)((ulonglong)puVar3[((ulonglong)uVar9 + 1) * 4] + lVar2),param_1,

                    (PVOID)(ulonglong)param_1->ExceptionCode,(PCONTEXT)param_4[5],

                    (PUNWIND_HISTORY_TABLE)param_4[8]);

        FUN_1402ccc10();

      }

LAB_1402c96bf:

    }

  }

  else {

    uVar8 = param_4[4] - lVar2;

    for (; uVar1 = *puVar3, uVar9 < uVar1; uVar9 = uVar9 + 1) {

      uVar10 = (ulonglong)uVar9;

      if ((puVar3[uVar10 * 4 + 1] <= uVar11) && (uVar11 < puVar3[uVar10 * 4 + 2])) {

        if ((param_1->ExceptionFlags & 0x20) != 0) {

          uVar7 = 0;

          if (uVar1 != 0) {

            do {

              if ((((puVar3[uVar7 * 4 + 1] <= uVar8) && (uVar8 < puVar3[uVar7 * 4 + 2])) &&

                  (puVar3[uVar7 * 4 + 4] == puVar3[uVar10 * 4 + 4])) &&

                 (puVar3[uVar7 * 4 + 3] == puVar3[uVar10 * 4 + 3])) break;

              uVar6 = (int)uVar7 + 1;

              uVar7 = (ulonglong)uVar6;

            } while (uVar6 < uVar1);

          }

          if ((uint)uVar7 != *puVar3) {

            return 1;

          }

        }

        if (puVar3[((ulonglong)uVar9 + 1) * 4] == 0) {

          *(uint *)(param_4 + 9) = uVar9 + 1;

          (*(code *)((ulonglong)puVar3[(ulonglong)uVar9 * 4 + 3] + lVar2))

                    (CONCAT71((int7)((ulonglong)uVar9 * 2 >> 8),1));

        }

        else if ((uVar8 == puVar3[((ulonglong)uVar9 + 1) * 4]) &&

                ((param_1->ExceptionFlags & 0x20) != 0)) {

          return 1;

        }

      }

    }

  }

  return 1;

}




