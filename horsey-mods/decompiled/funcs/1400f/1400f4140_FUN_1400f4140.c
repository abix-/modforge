// Address: 0x1400f4140
// Ghidra name: FUN_1400f4140
// ============ 0x1400f4140 FUN_1400f4140 (size=462) ============


bool FUN_1400f4140(longlong param_1,uint param_2,char *param_3,uint param_4)



{

  longlong lVar1;

  int iVar2;

  uint uVar3;

  size_t sVar4;

  char *pcVar5;

  int iVar6;

  

  sVar4 = strlen(param_3);

  lVar1 = param_1 + (ulonglong)param_2;

  iVar2 = FUN_1400f40d0(lVar1);

  if ((iVar2 != 0) &&

     ((param_4 == 0 ||

      (uVar3 = FUN_1400f4020(param_1,(ulonglong)param_2,&DAT_14030d7f4),

      ((*(byte *)((ulonglong)uVar3 + 0x2d + param_1) ^ param_4) & 7) == 0)))) {

    iVar2 = 0;

    iVar6 = (uint)*(byte *)(lVar1 + 4) * 0x100 + (uint)*(byte *)(lVar1 + 5);

    if (iVar6 != 0) {

      do {

        pcVar5 = (char *)((ulonglong)(iVar2 * 0x10 + param_2 + 0xc) + param_1);

        if ((((*pcVar5 == 'n') && (pcVar5[1] == 'a')) && (pcVar5[2] == 'm')) && (pcVar5[3] == 'e'))

        {

          iVar2 = (uint)(byte)pcVar5[9] * 0x10000 + (uint)(byte)pcVar5[10] * 0x100 +

                  (uint)(byte)pcVar5[8] * 0x1000000 + (uint)(byte)pcVar5[0xb];

          if (iVar2 == 0) {

            return false;

          }

          if (param_4 == 0) {

            iVar6 = FUN_1400f4310(param_1,iVar2,param_3,sVar4 & 0xffffffff,0x10,0x11);

            if ((iVar6 == 0) &&

               (iVar6 = FUN_1400f4310(param_1,iVar2,param_3,sVar4 & 0xffffffff,1,2), iVar6 == 0)) {

              iVar2 = FUN_1400f4310(param_1,iVar2,param_3,sVar4 & 0xffffffff,3,0xffffffff);

              return iVar2 != 0;

            }

          }

          else {

            iVar6 = FUN_1400f4310(param_1,iVar2,param_3,sVar4 & 0xffffffff,0x10,0xffffffff);

            if (((iVar6 == 0) &&

                (iVar6 = FUN_1400f4310(param_1,iVar2,param_3,sVar4 & 0xffffffff,1,0xffffffff),

                iVar6 == 0)) &&

               (iVar2 = FUN_1400f4310(param_1,iVar2,param_3,sVar4 & 0xffffffff,3,0xffffffff),

               iVar2 == 0)) {

              return false;

            }

          }

          return true;

        }

        iVar2 = iVar2 + 1;

      } while (iVar2 < iVar6);

    }

  }

  return false;

}




