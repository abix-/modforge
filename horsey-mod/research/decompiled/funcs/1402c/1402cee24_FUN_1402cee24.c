// Address: 0x1402cee24
// Ghidra name: FUN_1402cee24
// ============ 0x1402cee24 FUN_1402cee24 (size=390) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */



byte * FUN_1402cee24(FILE *param_1,byte *param_2,undefined8 param_3)



{

  uint uVar1;

  BOOL BVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  ulonglong uVar6;

  byte *pbVar7;

  longlong lVar8;

  undefined1 auStackY_1088 [32];

  DWORD local_1058 [3];

  byte abStack_1049 [4097];

  ulonglong local_48;

  undefined8 uStack_40;

  

  uStack_40 = 0x1402cee3e;

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStackY_1088;

  uVar1 = _fileno(param_1);

  lVar8 = 0;

  if (*(int *)&param_1->_base != 0) {

    uVar6 = (ulonglong)(uVar1 & 0x3f);

    lVar3 = ((longlong)param_1->_ptr - *(longlong *)&param_1->_cnt) / 2;

    lVar4 = thunk_FUN_1402eada0(uVar1,*(undefined8 *)

                                       ((&DAT_1403ff160)[(longlong)(int)uVar1 >> 6] + 0x30 +

                                       uVar6 * 0x48),0,param_3);

    if (lVar4 == *(longlong *)((&DAT_1403ff160)[(longlong)(int)uVar1 >> 6] + 0x30 + uVar6 * 0x48)) {

      local_1058[0] = 0;

      BVar2 = ReadFile(*(HANDLE *)

                        ((&DAT_1403ff160)[(longlong)(int)uVar1 >> 6] + 0x28 + uVar6 * 0x48),

                       abStack_1049 + 1,0x1000,local_1058,(LPOVERLAPPED)0x0);

      if (((BVar2 != 0) && (lVar5 = thunk_FUN_1402eada0(uVar1,param_2,0,param_3), -1 < lVar5)) &&

         (uVar6 = (ulonglong)local_1058[0], lVar3 <= (longlong)uVar6)) {

        pbVar7 = abStack_1049 + 1;

        if (lVar3 != 0) {

          do {

            if (abStack_1049 + uVar6 + 1 <= pbVar7) break;

            if (*pbVar7 == 0xd) {

              if ((pbVar7 < abStack_1049 + uVar6) && (pbVar7[1] == 10)) {

                pbVar7 = pbVar7 + 1;

              }

            }

            else {

              pbVar7 = pbVar7 + (char)(&DAT_1403e8ef0)[*pbVar7];

            }

            lVar8 = lVar8 + 1;

            pbVar7 = pbVar7 + 1;

          } while (lVar8 != lVar3);

        }

        return pbVar7 + (lVar4 - (longlong)(abStack_1049 + 1));

      }

    }

    param_2 = (byte *)0xffffffffffffffff;

  }

  return param_2;

}




