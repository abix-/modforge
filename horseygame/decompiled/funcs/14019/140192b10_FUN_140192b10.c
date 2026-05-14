// Address: 0x140192b10
// Ghidra name: FUN_140192b10
// ============ 0x140192b10 FUN_140192b10 (size=454) ============


longlong * FUN_140192b10(undefined8 param_1)



{

  char cVar1;

  int iVar2;

  longlong *plVar3;

  longlong *plVar4;

  longlong lVar5;

  longlong *plVar6;

  HANDLE hObject;

  longlong local_res10;

  undefined1 local_58 [4];

  ushort local_54;

  undefined2 local_52;

  undefined2 local_50;

  

  plVar3 = (longlong *)0x0;

  plVar6 = (longlong *)0x0;

  local_res10 = 0;

  hObject = (HANDLE)0xffffffffffffffff;

  iVar2 = FUN_140192a10();

  plVar4 = plVar3;

  if (-1 < iVar2) {

    plVar3 = (longlong *)FUN_140195b70(param_1);

    plVar4 = plVar6;

    if (plVar3 == (longlong *)0x0) {

      FUN_140196b40(L"Path conversion failure");

    }

    else {

      hObject = (HANDLE)FUN_1401967f0(plVar3,1);

      if (hObject == (HANDLE)0xffffffffffffffff) {

        hObject = (HANDLE)FUN_1401967f0(plVar3,0);

        if (hObject == (HANDLE)0xffffffffffffffff) {

          FUN_140196b50(L"open_device");

          goto LAB_140192c9a;

        }

      }

      cVar1 = (*DAT_1403fcca8)(hObject,0x40);

      if (cVar1 == '\0') {

        FUN_140196b50(L"set input buffers");

      }

      else {

        cVar1 = (*DAT_1403fcc90)(hObject,&local_res10);

        if (cVar1 == '\0') {

          FUN_140196b50(L"get preparsed data");

        }

        else {

          iVar2 = (*DAT_1403fcca0)(local_res10,local_58);

          if (iVar2 == 0x110000) {

            plVar4 = (longlong *)FUN_140192ce0();

            if (plVar4 == (longlong *)0x0) {

              FUN_140196b40(L"hid_device allocation error");

            }

            else {

              *plVar4 = (longlong)hObject;

              hObject = (HANDLE)0xffffffffffffffff;

              *(undefined2 *)((longlong)plVar4 + 0xc) = local_52;

              plVar4[3] = (ulonglong)local_54;

              *(undefined2 *)(plVar4 + 4) = local_50;

              lVar5 = FUN_1401841f0();

              plVar4[8] = lVar5;

              lVar5 = FUN_140195f10(plVar3,*plVar4);

              plVar4[0x11] = lVar5;

              if (0x200 < *(ushort *)((longlong)plVar4 + 0xc)) {

                iVar2 = FUN_1401925a0(6,2,0);

                *(uint *)(plVar4 + 0x12) = (uint)(iVar2 == 0);

              }

            }

          }

          else {

            FUN_140196b40(L"HidP_GetCaps");

          }

        }

      }

    }

  }

LAB_140192c9a:

  FUN_1401841e0(plVar3);

  CloseHandle(hObject);

  if (local_res10 != 0) {

    (*DAT_1403fcc98)();

  }

  return plVar4;

}




