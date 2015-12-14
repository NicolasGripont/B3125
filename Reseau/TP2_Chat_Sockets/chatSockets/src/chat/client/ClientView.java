/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chat.client;

import chat.Message;
import java.rmi.RemoteException;
import java.util.Date;

/**
 *
 * @author Nico
 */
public class ClientView extends javax.swing.JFrame implements ClientViewInterface {

    private Client client;

    /**
     * Creates new form Test
     */
    public ClientView() {
        initComponents();
        client = new Client(this);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel2 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        serverAddressField = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        usernameField = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        serverPortField = new javax.swing.JTextField();
        filler1 = new javax.swing.Box.Filler(new java.awt.Dimension(0, 10), new java.awt.Dimension(0, 10), new java.awt.Dimension(32767, 10));
        connectButton = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        messagesField = new javax.swing.JTextArea();
        jPanel1 = new javax.swing.JPanel();
        messageField = new javax.swing.JTextField();
        sendButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setMaximumSize(new java.awt.Dimension(600, 500));
        setMinimumSize(new java.awt.Dimension(600, 500));
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });
        getContentPane().setLayout(new javax.swing.BoxLayout(getContentPane(), javax.swing.BoxLayout.PAGE_AXIS));

        jPanel2.setMaximumSize(new java.awt.Dimension(32767, 100));
        jPanel2.setLayout(new java.awt.GridLayout(2, 0));

        jLabel2.setText("Server address :");
        jPanel2.add(jLabel2);

        serverAddressField.setText("localhost");
        serverAddressField.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                serverAddressFieldFocusGained(evt);
            }
        });
        serverAddressField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                serverAddressFieldActionPerformed(evt);
            }
        });
        jPanel2.add(serverAddressField);

        jLabel1.setText("Enter your name : ");
        jPanel2.add(jLabel1);

        usernameField.setText("unknown");
        usernameField.setMaximumSize(new java.awt.Dimension(2147483647, 28));
        usernameField.addFocusListener(new java.awt.event.FocusAdapter() {
            public void focusGained(java.awt.event.FocusEvent evt) {
                usernameFieldFocusGained(evt);
            }
        });
        jPanel2.add(usernameField);

        jLabel3.setText("Server port :");
        jPanel2.add(jLabel3);

        serverPortField.setText("1099");
        serverPortField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                serverPortFieldActionPerformed(evt);
            }
        });
        jPanel2.add(serverPortField);
        jPanel2.add(filler1);

        connectButton.setText("Connect");
        connectButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                connectButtonActionPerformed(evt);
            }
        });
        jPanel2.add(connectButton);

        getContentPane().add(jPanel2);

        messagesField.setColumns(20);
        messagesField.setRows(5);
        jScrollPane1.setViewportView(messagesField);

        getContentPane().add(jScrollPane1);

        jPanel1.setLayout(new javax.swing.BoxLayout(jPanel1, javax.swing.BoxLayout.LINE_AXIS));

        messageField.setMaximumSize(new java.awt.Dimension(2147483647, 100));
        messageField.setMinimumSize(new java.awt.Dimension(14, 100));
        messageField.setPreferredSize(new java.awt.Dimension(84, 100));
        messageField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                messageFieldActionPerformed(evt);
            }
        });
        jPanel1.add(messageField);

        sendButton.setText("Send");
        sendButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                sendButtonActionPerformed(evt);
            }
        });
        jPanel1.add(sendButton);

        getContentPane().add(jPanel1);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void messageFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_messageFieldActionPerformed
        // TODO add your handling code here:
        sendMessage();
    }//GEN-LAST:event_messageFieldActionPerformed

    private void serverAddressFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_serverAddressFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_serverAddressFieldActionPerformed

    private void sendButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_sendButtonActionPerformed
        // TODO add your handling code here:
        sendMessage();
    }//GEN-LAST:event_sendButtonActionPerformed

    private void sendMessage(){
        if (client.isConnected()) {
            client.sendMessage(messageField.getText());
            messageField.setText("");
        }
    }

    private void connectButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_connectButtonActionPerformed
        // TODO add your handling code here:
        if (!client.isConnected()) {
            String adr = serverAddressField.getText();
            if (adr.compareTo("localhost") == 0) {
                adr = null;
            }
            client.setServername(adr);
            client.setServerport(Integer.parseInt(serverPortField.getText()));
            client.setUsername(usernameField.getText());
            if (client.connect()){
                connectButton.setText("Disconnect"); 
            }
        } else {
            client.disconnect();
            connectButton.setText("Connect");
            messagesField.setText("");
        }
    }//GEN-LAST:event_connectButtonActionPerformed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        // TODO add your handling code here:
        if (client.isConnected()) {
            client.disconnect();
        }
    }//GEN-LAST:event_formWindowClosing

    private void usernameFieldFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_usernameFieldFocusGained
        // TODO add your handling code here:
        usernameField.selectAll();
    }//GEN-LAST:event_usernameFieldFocusGained

    private void serverAddressFieldFocusGained(java.awt.event.FocusEvent evt) {//GEN-FIRST:event_serverAddressFieldFocusGained
        // TODO add your handling code here:
        serverAddressField.selectAll();
    }//GEN-LAST:event_serverAddressFieldFocusGained

    private void serverPortFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_serverPortFieldActionPerformed
        // TODO add your handling code here:
        serverPortField.selectAll();
    }//GEN-LAST:event_serverPortFieldActionPerformed

    @Override
    public void displayMessage(Message m) throws RemoteException {
        // TODO Auto-generated method stub
        StringBuilder sb = new StringBuilder();
        sb.append(messagesField.getText());
        Date d = m.getDate();
        String date = String.format("%d/%d/%d %d:%d:%d", d.getDay(), d.getMonth(), d.getYear() + 1900, d.getHours(), d.getMinutes(), d.getSeconds());
        sb.append(String.format("[%s] %s : %s", date, m.getUserName(), m.getTextMessage()));
        sb.append("\n");
        messagesField.setText(sb.toString());
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(ClientView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(ClientView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(ClientView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(ClientView.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new ClientView().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton connectButton;
    private javax.swing.Box.Filler filler1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextField messageField;
    private javax.swing.JTextArea messagesField;
    private javax.swing.JButton sendButton;
    private javax.swing.JTextField serverAddressField;
    private javax.swing.JTextField serverPortField;
    private javax.swing.JTextField usernameField;
    // End of variables declaration//GEN-END:variables
}
