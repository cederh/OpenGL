#!/usr/bin/env python

# create a  single wx frame with pexpect and pxssh libraries
# for shutdown pcs with a ip asigned
# tested with wxPython2.7  by   LJA 13112015
import wx
import pexpect
import pxssh
import os
import sys
import subprocess

class MyFrame(wx.Frame):
    """make a frame, inherits wx.Frame"""
    def __init__(self):
        wx.Frame.__init__(self, None, wx.ID_ANY, 'Apagar PC Sala',pos=(300, 150), size=(240, 420))
        self.SetBackgroundColour("gray")
        # pc 1
        self.button1 = wx.Button(self, id=-1, label='PC-1',pos=(20, 10), size=(100, 28))
        self.button1.Bind(wx.EVT_BUTTON, self.button1Click)
        self.button1.SetToolTip(wx.ToolTip("shutdown"))
        # pc 2
        self.button2 = wx.Button(self, id=-1, label='PC-2',pos=(20, 40), size=(100, 28))
        self.button2.Bind(wx.EVT_BUTTON, self.button2Click)
        self.button2.SetToolTip(wx.ToolTip("shutdown"))        
        # pc 3
        self.button3 = wx.Button(self, id=-1, label='PC-3',pos=(20, 70), size=(100, 28))
        self.button3.Bind(wx.EVT_BUTTON, self.button3Click)
        self.button3.SetToolTip(wx.ToolTip("shutdown"))
        # pc 4
        self.button4 = wx.Button(self, id=-1, label='PC-4', pos=(20, 100), size=(100, 28))
        self.button4.Bind(wx.EVT_BUTTON, self.button4Click)
        self.button4.SetToolTip(wx.ToolTip("shutdown"))
        #pc 5
        self.button5 = wx.Button(self, id=-1, label='PC-5', pos=(20, 130), size=(100, 28))
        self.button5.Bind(wx.EVT_BUTTON, self.button5Click)
        self.button5.SetToolTip(wx.ToolTip("shuddown ip"))
        #pc 6
        self.button6 = wx.Button(self, id=-1, label='PC-6',pos=(20, 160), size=(100, 28))
        self.button6.Bind(wx.EVT_BUTTON, self.button6Click)
        self.button6.SetToolTip(wx.ToolTip("shuddown ip"))
        #pc-7
        self.button7 = wx.Button(self, id=-1, label='PC-7',pos=(20, 190), size=(100, 28))
        self.button7.Bind(wx.EVT_BUTTON, self.button7Click)
        self.button7.SetToolTip(wx.ToolTip("shuddown ip"))
        #pc-8
        self.button8 = wx.Button(self, id=-1, label='PC-8',pos=(20, 220), size=(100, 28))
        self.button8.Bind(wx.EVT_BUTTON, self.button8Click)
        self.button8.SetToolTip(wx.ToolTip("shuddown ip 8"))
        #pc-9
        self.button9 = wx.Button(self, id=-1, label='PC-9',pos=(20, 250), size=(100, 28))
        self.button9.Bind(wx.EVT_BUTTON, self.button9Click)
        self.button9.SetToolTip(wx.ToolTip("shuddown ip 9"))
        #pc-10
        self.button10 = wx.Button(self, id=-1, label='PC-10',pos=(20, 280), size=(100, 28))
        self.button10.Bind(wx.EVT_BUTTON, self.button10Click)
        self.button10.SetToolTip(wx.ToolTip("shuddown ip 10"))
        #pc-11
        self.button11 = wx.Button(self, id=-1, label='PC-11',pos=(120, 10), size=(100, 28))
        self.button11.Bind(wx.EVT_BUTTON, self.button11Click)
        self.button11.SetToolTip(wx.ToolTip("shuddown ip 11")) 
        #pc-12
        self.button12 = wx.Button(self, id=-1, label='PC-12',pos=(120, 40), size=(100, 28))
        self.button12.Bind(wx.EVT_BUTTON, self.button12Click)
        self.button12.SetToolTip(wx.ToolTip("shuddown ip 11")) 
        #pc-13
        self.button13 = wx.Button(self, id=-1, label='PC-13',pos=(120, 70), size=(100, 28))
        self.button13.Bind(wx.EVT_BUTTON, self.button13Click)
        self.button13.SetToolTip(wx.ToolTip("shuddown ip 13")) 
        #pc-14
        self.button14 = wx.Button(self, id=-1, label='PC-14',pos=(120, 100), size=(100, 28))
        self.button14.Bind(wx.EVT_BUTTON, self.button14Click)
        self.button14.SetToolTip(wx.ToolTip("shuddown ip 14")) 
        #pc-15
        self.button15 = wx.Button(self, id=-1, label='PC-15',pos=(120, 130), size=(100, 28))
        self.button15.Bind(wx.EVT_BUTTON, self.button15Click)
        self.button15.SetToolTip(wx.ToolTip("shuddown ip 15")) 
        #pc-16
        self.button16 = wx.Button(self, id=-1, label='PC-16',pos=(120, 160), size=(100, 28))
        self.button16.Bind(wx.EVT_BUTTON, self.button16Click)
        self.button16.SetToolTip(wx.ToolTip("shuddown ip 16")) 
        #pc-17
        self.button17 = wx.Button(self, id=-1, label='PC-17',pos=(120, 190), size=(100, 28))
        self.button17.Bind(wx.EVT_BUTTON, self.button17Click)
        self.button17.SetToolTip(wx.ToolTip("shuddown ip 17")) 
        #pc-18
        self.button18 = wx.Button(self, id=-1, label='PC-18',pos=(120, 220), size=(100, 28))
        self.button18.Bind(wx.EVT_BUTTON, self.button18Click)
        self.button18.SetToolTip(wx.ToolTip("shuddown ip 18")) 
        #pc-19
        self.button19 = wx.Button(self, id=-1, label='PC-19',pos=(120, 250), size=(100, 28))
        self.button19.Bind(wx.EVT_BUTTON, self.button19Click)
        self.button19.SetToolTip(wx.ToolTip("shuddown ip 19")) 
           
        #Seleccionar comando con Radio Buttons
        self.rb1 = wx.RadioButton(self,id=-1, label='Apagar', pos=(20, 320), style=wx.RB_GROUP)
        self.rb2 = wx.RadioButton(self,id=-1, label='Reiniciar', pos=(120, 320))    
        #self.label = wx.StaticText(self,id=-1, label="Test", pos=(150, 350))    
        self.rb1.Bind(wx.EVT_RADIOBUTTON, self.onButton)
        self.rb2.Bind(wx.EVT_RADIOBUTTON, self.onButton)

		#texto pie de pagina
        self.footer1 = wx.StaticText(self, label="", pos=(50, 430))
        self.username = 'root'
        self.password='12345678$'
        self.command='poweroff'
        self.state1='True'
        self.Show(True)

        self.todos = wx.Button(self, id=-1, label='Apagar Todos!',pos=(60, 370), size=(110, 28))
        self.todos.Bind(wx.EVT_BUTTON, self.todosClick)
        self.todos.SetToolTip(wx.ToolTip("shutdown all computers registered!"))
    
    def onButton(self, event):
        """
        This method is fired when its corresponding button is pressed
        """
        btn = event.GetEventObject()
        label = btn.GetLabel()
        message = "Ha seleccionado %s" % label
        dlg = wx.MessageDialog(None, message, 'Message', 
                               wx.OK|wx.ICON_EXCLAMATION)
        dlg.ShowModal()
        dlg.Destroy()
        if (label=='Apagar'):
            self.command='poweroff'
        else:
            self.command='reboot'

    def button1Click(self,event):
		self.password='12345678$'
		self.hostname='192.168.14.11'
		self.SetTitle("shutdown ip: "+self.hostname)        
		self.state1 = str(self.rb1.GetValue())
		self.state2 = str(self.rb2.GetValue())
        #self.label.SetLabel(self.state1)
		if (self.state1=='True'):
			self.command='ls -la'
		if (self.state2=='True'):
			self.command='reboot'
		child = ssh_command (self.username, self.hostname, self.password, self.command)
		child.expect(pexpect.EOF)
		print child.before
    def button2Click(self,event):
        #self.button2.Disable()
        self.hostname='192.168.14.12'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button3Click(self,event):
        #self.button4.Disable()
        self.hostname='192.168.14.13'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button4Click(self,event):
        self.hostname='192.168.14.14'
        self.SetTitle("shutdown ip: "+self.hostname)        
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button5Click(self,event):
        self.hostname='192.168.14.15'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button6Click(self,event):
        self.hostname='192.168.14.16'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button7Click(self,event):
        self.hostname='192.168.14.17'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before     
    def button8Click(self,event):
        #self.button7.Disable()
        self.hostname='192.168.14.18'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before      
    def button9Click(self,event):
        #self.button7.Disable()
        self.hostname='192.168.14.19'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button10Click(self,event):
        #self.button10.Disable()
        self.hostname='192.168.14.20'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button11Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.21'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button12Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.22'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button13Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.23'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button14Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.24'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button15Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.25'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button16Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.26'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button17Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.31'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button18Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.10'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    def button19Click(self,event):
        #self.button11.Disable()
        self.hostname='192.168.14.29'
        self.SetTitle("shutdown ip: "+self.hostname)
        child = ssh_command (self.username, self.hostname, self.password, self.command)
        child.expect(pexpect.EOF)
        print child.before
    
    def todosClick(self,event):
        #self.button11.Disable() 
        cmd='sh /home/user/scripts/apagar2.sh'       
        self.SetTitle("shutdown all registered ip ")
        p=subprocess.Popen(cmd, shell=True, stderr=subprocess.PIPE)
        while True:
			out=p.stderr.read(1)
			if out=='' and p.poll()!=None:
				break
			if out !='':
				sys.stdout.write(out)
				sys.stdout.flush	
			
def ssh_command(user, host, password, command):

    """This runs a command on the remote host. This could also be done with the
    pxssh class, but this demonstrates what that class does at a simpler level.
    This returns a pexpect.spawn object. This handles the case when you try to
    connect to a new host and ssh asks you if you want to accept the public key
    fingerprint and continue connecting. """

    ssh_newkey = 'Are you sure you want to continue connecting'
    child = pexpect.spawn('ssh -l %s %s %s'%(user, host, command))
    i = child.expect([pexpect.TIMEOUT, ssh_newkey, 'password: '])
    if i == 0: # Timeout
        print 'ERROR!'
        print 'SSH could not login. Here is what SSH said:'
        print child.before, child.after
        return None
    if i == 1: # SSH does not have the public key. Just accept it.
        child.sendline ('yes')
        child.expect ('password:')
        i = child.expect([pexpect.TIMEOUT, 'password: '])
        if i == 0: # Timeout
            print 'ERROR!'
            print 'SSH could not login. Here is what SSH said:'
            print child.before, child.after
            return None       
    child.sendline(password)
    return child

application = wx.PySimpleApp()
# call class MyFrame
window = MyFrame()
# start the event loop
application.MainLoop()

