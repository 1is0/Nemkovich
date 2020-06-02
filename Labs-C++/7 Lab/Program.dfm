object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Lab7V1 (by Nemkovich)'
  ClientHeight = 276
  ClientWidth = 549
  Color = clMoneyGreen
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 193
    Width = 70
    Height = 13
    Caption = #1069#1083'. '#1090#1072#1073#1083#1080#1094#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 220
    Width = 58
    Height = 13
    Caption = #1050#1086#1083'-'#1074#1086' '#1101#1083'.:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 143
    Top = 13
    Width = 59
    Height = 13
    Caption = #1069#1083#1077#1084#1077#1085#1090#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 215
    Top = 13
    Width = 71
    Height = 13
    Caption = #1061#1101#1096' '#1090#1072#1073#1083#1080#1094#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label5: TLabel
    Left = 327
    Top = 13
    Width = 100
    Height = 13
    Caption = #1061#1101#1096' '#1090#1072#1073#1083#1080#1094#1072' '#1089' "+":'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label6: TLabel
    Left = 439
    Top = 13
    Width = 98
    Height = 13
    Caption = #1061#1101#1096' '#1090#1072#1073#1083#1080#1094#1072' '#1089' "-":'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 129
    Height = 25
    Caption = 'Generate keys'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 39
    Width = 129
    Height = 25
    Caption = 'Print'
    Enabled = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 70
    Width = 73
    Height = 25
    Caption = 'Find'
    Enabled = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Edit1: TEdit
    Left = 87
    Top = 190
    Width = 50
    Height = 21
    TabOrder = 3
    Text = '15'
  end
  object Edit2: TEdit
    Left = 87
    Top = 217
    Width = 50
    Height = 21
    TabOrder = 4
    Text = '15'
  end
  object Edit3: TEdit
    Left = 103
    Top = 101
    Width = 34
    Height = 21
    Enabled = False
    TabOrder = 5
  end
  object Edit4: TEdit
    Left = 87
    Top = 163
    Width = 50
    Height = 21
    Enabled = False
    TabOrder = 6
  end
  object Edit5: TEdit
    Left = 87
    Top = 72
    Width = 50
    Height = 21
    Enabled = False
    TabOrder = 7
  end
  object Button4: TButton
    Left = 8
    Top = 99
    Width = 89
    Height = 25
    Caption = 'Delete stack '#8470
    Enabled = False
    TabOrder = 8
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 159
    Width = 73
    Height = 25
    Caption = 'Add'
    Enabled = False
    TabOrder = 9
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 132
    Width = 89
    Height = 25
    Caption = 'Delete element'
    Enabled = False
    TabOrder = 10
    OnClick = Button6Click
  end
  object Edit6: TEdit
    Left = 103
    Top = 132
    Width = 34
    Height = 21
    Enabled = False
    TabOrder = 11
  end
  object Memo1: TMemo
    Left = 143
    Top = 32
    Width = 66
    Height = 208
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 12
  end
  object Memo2: TMemo
    Left = 215
    Top = 32
    Width = 106
    Height = 208
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 13
  end
  object Memo3: TMemo
    Left = 327
    Top = 32
    Width = 106
    Height = 208
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 14
  end
  object Memo4: TMemo
    Left = 439
    Top = 32
    Width = 106
    Height = 208
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 15
  end
  object Button7: TButton
    Left = 8
    Top = 243
    Width = 537
    Height = 25
    Caption = 'Exit'
    TabOrder = 16
    OnClick = Button7Click
  end
end
