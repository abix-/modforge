// Address: 0x14012dbb0
// Ghidra name: FUN_14012dbb0
// ============ 0x14012dbb0 FUN_14012dbb0 (size=587) ============


void FUN_14012dbb0(char *param_1)



{

  char *_Str;

  char cVar1;

  longlong lVar2;

  size_t sVar3;

  longlong lVar4;

  char *pcVar5;

  int local_res10 [2];

  int local_res18 [2];

  

  local_res18[0] = -1;

  local_res10[0] = 0;

  lVar2 = thunk_FUN_1402c9190(param_1,0x3d);

  if (lVar2 == 0) {

    sVar3 = strlen(param_1);

    cVar1 = FUN_14012de00(param_1,sVar3,local_res10);

    if (cVar1 != '\0') {

      FUN_14012e570(local_res10[0]);

      return;

    }

  }

  else {

    while ((param_1 != (char *)0x0 && (lVar2 = thunk_FUN_1402c9190(param_1,0x3d), lVar2 != 0))) {

      lVar4 = thunk_FUN_1402c9190(lVar2,0x2c);

      pcVar5 = (char *)(lVar4 + 1);

      if (lVar4 == 0) {

        pcVar5 = (char *)0x0;

      }

      cVar1 = FUN_14012dae0(param_1,lVar2 - (longlong)param_1,local_res18);

      param_1 = pcVar5;

      if (cVar1 != '\0') {

        _Str = (char *)(lVar2 + 1);

        if (pcVar5 == (char *)0x0) {

          pcVar5 = (char *)strlen(_Str);

        }

        else {

          pcVar5 = pcVar5 + (-1 - (longlong)_Str);

        }

        cVar1 = FUN_14012de00(_Str,pcVar5,local_res10);

        if (cVar1 != '\0') {

          if (local_res18[0] == -1) {

            if (DAT_1403fb530 == 0) {

              DAT_1403fb530 = local_res10[0];

            }

            if (DAT_1403fb534 == 0) {

              DAT_1403fb534 = local_res10[0];

            }

            if (DAT_1403fb538 == 0) {

              DAT_1403fb538 = local_res10[0];

            }

            if (DAT_1403fb53c == 0) {

              DAT_1403fb53c = local_res10[0];

            }

            if (DAT_1403fb540 == 0) {

              DAT_1403fb540 = local_res10[0];

            }

            if (DAT_1403fb544 == 0) {

              DAT_1403fb544 = local_res10[0];

            }

            if (DAT_1403fb548 == 0) {

              DAT_1403fb548 = local_res10[0];

            }

            if (DAT_1403fb54c == 0) {

              DAT_1403fb54c = local_res10[0];

            }

            if (DAT_1403fb550 == 0) {

              DAT_1403fb550 = local_res10[0];

            }

            if (DAT_1403fb554 == 0) {

              DAT_1403fb554 = local_res10[0];

            }

            if (DAT_1403fb558 == 0) {

              DAT_1403fb558 = local_res10[0];

            }

            if (DAT_1403fb55c == 0) {

              DAT_1403fb55c = local_res10[0];

            }

            if (DAT_1403fb560 == 0) {

              DAT_1403fb560 = local_res10[0];

            }

            if (DAT_1403fb564 == 0) {

              DAT_1403fb564 = local_res10[0];

            }

            if (DAT_1403fb568 == 0) {

              DAT_1403fb568 = local_res10[0];

            }

            if (DAT_1403fb56c == 0) {

              DAT_1403fb56c = local_res10[0];

            }

            if (DAT_1403fb570 == 0) {

              DAT_1403fb570 = local_res10[0];

            }

            if (DAT_1403fb574 == 0) {

              DAT_1403fb574 = local_res10[0];

            }

            DAT_1403fb4f4 = local_res10[0];

            if (DAT_1403fb578 == 0) {

              DAT_1403fb578 = local_res10[0];

            }

          }

          else {

            FUN_14012e680(local_res18[0],local_res10[0]);

          }

        }

      }

    }

  }

  return;

}




