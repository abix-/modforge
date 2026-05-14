// Address: 0x140267690
// Ghidra name: FUN_140267690
// ============ 0x140267690 FUN_140267690 (size=321) ============


undefined8 FUN_140267690(ushort *param_1,ushort *param_2,ulonglong param_3)



{

  ushort uVar1;

  char cVar2;

  undefined8 uVar3;

  int iVar4;

  uint local_res18 [2];

  

  iVar4 = (int)param_3;

  if (0xf < iVar4) {

    local_res18[0] = (uint)*param_2;

    if (((int)local_res18[0] <= iVar4) && (0xf < local_res18[0])) {

      uVar1 = param_2[1];

      *param_1 = (ushort)(byte)uVar1;

      *param_1 = CONCAT11(*(undefined1 *)((longlong)param_2 + 3),(byte)uVar1);

      uVar1 = param_2[2];

      param_1[1] = (ushort)(byte)uVar1;

      param_1[1] = CONCAT11(*(undefined1 *)((longlong)param_2 + 5),(byte)uVar1);

      if (((int)(uint)param_2[7] <= iVar4) && (local_res18[0] <= param_2[7])) {

        cVar2 = FUN_140267290(param_1,param_2,param_3,local_res18);

        if ((cVar2 != '\0') && ((int)local_res18[0] < iVar4)) {

          cVar2 = *(char *)((longlong)(int)local_res18[0] + (longlong)param_2);

          local_res18[0] = local_res18[0] + 1;

          *(char *)(param_1 + 0x3c) = cVar2;

          if (cVar2 != '\0') {

            uVar3 = FUN_1401841a0(cVar2,0x10);

            iVar4 = 0;

            *(undefined8 *)(param_1 + 0x40) = uVar3;

            if ((char)param_1[0x3c] != '\0') {

              do {

                cVar2 = FUN_140267580((longlong)iVar4 * 0x10 + *(longlong *)(param_1 + 0x40),param_2

                                      ,param_3 & 0xffffffff,local_res18);

                if (cVar2 == '\0') goto LAB_1402677b3;

                iVar4 = iVar4 + 1;

              } while (iVar4 < (int)(uint)(byte)param_1[0x3c]);

            }

          }

          return 1;

        }

LAB_1402677b3:

        FUN_1402671e0(param_1);

        return 0;

      }

    }

  }

  return 0;

}




