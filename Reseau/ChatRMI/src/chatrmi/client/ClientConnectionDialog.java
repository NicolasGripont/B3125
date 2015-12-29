/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatrmi.client;

import java.awt.Component;
import java.awt.Window;
import javax.swing.SwingUtilities;

/**
 *
 * @author Nico
 */
public class ClientConnectionDialog extends javax.swing.JDialog {

    Client client;
    /**
     * Creates new form NewJDialog
     */
    public ClientConnectionDialog(java.awt.Frame parent, boolean modal, Client c) {
        super(parent, modal);
        initComponents();
        client = c;
        setLocationRelativeTo(null);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        serverAdressTextField = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        serverPortTextField = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        usernameTextField = new javax.swing.JTextField();
        connectButton = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setMaximumSize(new java.awt.Dimension(320, 180));
        setMinimumSize(new java.awt.Dimension(320, 180));
        setPreferredSize(new java.awt.Dimension(320, 180));
        getContentPane().setLayout(new java.awt.FlowLayout());

        jPanel1.setMinimumSize(new java.awt.Dimension(300, 100));
        jPanel1.setPreferredSize(new java.awt.Dimension(300, 100));
        jPanel1.setLayout(new java.awt.GridLayout(3, 2));

        jLabel2.setText("Server adress : ");
        jPanel1.add(jLabel2);

        serverAdressTextField.setText("localhost");
        serverAdressTextField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                serverAdressTextFieldActionPerformed(evt);
            }
        });
        jPanel1.add(serverAdressTextField);

        jLabel3.setText("Server port : ");
        jPanel1.add(jLabel3);

        serverPortTextField.setText("1099");
        serverPortTextField.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                serverPortTextFieldActionPerformed(evt);
            }
        });
        jPanel1.add(serverPortTextField);

        jLabel4.setText("User name : ");
        jPanel1.add(jLabel4);

        usernameTextField.setText("Unknown");
        jPanel1.add(usernameTextField);

        getContentPane().add(jPanel1);

        connectButton.setText("Connect");
        connectButton.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        connectButton.setMaximumSize(new java.awt.Dimension(20, 100));
        connectButton.setMinimumSize(new java.awt.Dimension(20, 100));
        connectButton.setPreferredSize(new java.awt.Dimension(150, 30));
        connectButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                connectButtonActionPerformed(evt);
            }
        });
        getContentPane().add(connectButton);

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void serverAdressTextFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_serverAdressTextFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_serverAdressTextFieldActionPerformed

    private void serverPortTextFieldActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_serverPortTextFieldActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_serverPortTextFieldActionPerformed

    private void connectButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_connectButtonActionPerformed
        // TODO add your handling code here:
        if (client.connect(serverAdressTextField.getText(),serverPortTextField.getText(),usernameTextField.getText()))
        {
            Window window = SwingUtilities.windowForComponent((Component)evt.getSource());
            window.dispose();
        }
    }//GEN-LAST:event_connectButtonActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton connectButton;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JTextField serverAdressTextField;
    private javax.swing.JTextField serverPortTextField;
    private javax.swing.JTextField usernameTextField;
    // End of variables declaration//GEN-END:variables
}
